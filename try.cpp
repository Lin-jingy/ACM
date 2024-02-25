#include <vector>
#include <stdexcept>
#include <iostream>

// 定义一个自定义的bitset类，模仿std::bitset的行为，允许通过下标访问和修改比特位
class MyBitset {
public:
    // 构造函数，初始化bitset大小
    explicit MyBitset(size_t size) 
        : data((size + sizeof(unsigned int) * CHAR_BIT - 1) / (sizeof(unsigned int) * CHAR_BIT)), // 计算需要存储的整数数量（向上取整以容纳所有比特位）
          bits_size(size) {} // 存储总比特位数

    // 内部代理类，用于表示单个比特位的引用，并支持布尔类型转换和赋值操作
    class BitRef {
    public:
        // 构造函数，接收bitset实例的所有权指针和比特位位置
        BitRef(MyBitset* owner, size_t pos) : owner(owner), pos(pos) {}

        // 类型转换运算符，返回该比特位对应的bool值
        operator bool() const { return owner->test(pos); }

        // 赋值运算符，设置指定比特位为给定的bool值
        BitRef& operator=(bool value) {
            owner->set(pos, value);
            return *this;
        }

    private:
        MyBitset* owner; // 持有bitset实例的指针
        size_t pos;      // 指定比特位的位置
    };

    // 下标访问运算符重载，返回对应比特位的引用
    BitRef operator[](size_t pos) {
        // 检查索引是否越界
        if (pos >= bits_size) {
            throw std::out_of_range("Bitset index out of range");
        }
        
        // 返回内部代理类对象，持有当前bitset实例和目标比特位位置
        return BitRef(this, pos);
    }

    // 设置指定位置的比特位为给定的bool值
    void set(size_t pos, bool value) {
        // 检查索引是否越界
        if (pos >= bits_size) {
            throw std::out_of_range("Bitset index out of range");
        }
        
        // 计算比特位所在的整数索引和该整数内的位偏移
        size_t word_index = pos / (sizeof(unsigned int) * CHAR_BIT);
        size_t bit_offset = pos % (sizeof(unsigned int) * CHAR_BIT);

        // 创建掩码并根据value设置或清除相应比特位
        unsigned int mask = 1 << bit_offset;
        if (value)
            data[word_index] |= mask; // 设置比特位
        else
            data[word_index] &= ~mask; // 清除比特位
    }

    // 测试指定位置的比特位是否为1
    bool test(size_t pos) const {
        // 检查索引是否越界
        if (pos >= bits_size) {
            throw std::out_of_range("Bitset index out of range");
        }
        
        // 计算比特位所在的整数索引和该整数内的位偏移
        size_t word_index = pos / (sizeof(unsigned int) * CHAR_BIT);
        size_t bit_offset = pos % (sizeof(unsigned int) * CHAR_BIT);

        // 使用按位与运算检查比特位是否为1
        return (data[word_index] & (1 << bit_offset)) != 0;
    }

private:
    // 使用vector来存储unsigned int类型的整数数组，用于存放实际的比特位数据
    std::vector<unsigned int> data;

    // 存储bitset的总位数
    size_t bits_size;
};

int main() {
    MyBitset bs(100);
    bs[5] = true;
    std::cout << (bool)bs[5] << std::endl;
}

