#include <iostream>
#include <stdexcept>

#include "../Array.hpp"

// 测试框架
#define TEST(name) void name()
#define CHECK(cond, msg)                                                \
    do {                                                                \
        if (!(cond)) {                                                  \
            std::cerr << "Test failed: " << #cond << " (" << msg << ")" \
                      << std::endl;                                     \
            exit(1);                                                    \
        }                                                               \
    } while (0)

// 测试Array类的模板
template <typename T, std::size_t N>
class ArrayTest {
   public:
    static void runTests() {
        ConstructorsAndAssignment();
        ElementAccess();
        Iterators();
        Capacity();
        Operations();
        ComparisonOperators();
        GetFunction();
        SwapFunction();
    }

   private:
    static void ConstructorsAndAssignment() {
        Array<T, N> arr1 = {1, 2, 3, 4};
        Array<T, N> arr2 = arr1;
        Array<T, N> arr3;
        arr3 = arr1;

        CHECK(arr1 == arr2, "Constructors and assignment failed");
        CHECK(arr1 == arr3, "Constructors and assignment failed");
    }

    static void ElementAccess() {
        Array<T, N> arr = {1, 2, 3, 4};

        CHECK(arr[0] == 1, "Element access failed");
        CHECK(arr[1] == 2, "Element access failed");
        CHECK(arr[2] == 3, "Element access failed");
        CHECK(arr[3] == 4, "Element access failed");
    }

    static void Iterators() {
        Array<T, N> arr = {1, 2, 3, 4};

        auto it = arr.begin();
        CHECK(*it == 1, "Iterator access failed");
        ++it;
        CHECK(*it == 2, "Iterator access failed");

        auto rit = arr.rbegin();
        CHECK(*rit == 4, "Reverse iterator access failed");
        ++rit;
        CHECK(*rit == 3, "Reverse iterator access failed");
    }

    static void Capacity() {
        Array<T, N> arr;

        CHECK(!arr.empty(), "Empty check failed");
        CHECK(arr.size() == N, "Size check failed");
        CHECK(arr.max_size() == N, "Max size check failed");
    }

    static void Operations() {
        Array<T, N> arr = {1, 2, 3, 4};

        arr.fill(5);
        CHECK(arr[0] == 5, "Fill operation failed");
        CHECK(arr[1] == 5, "Fill operation failed");
        CHECK(arr[2] == 5, "Fill operation failed");
        CHECK(arr[3] == 5, "Fill operation failed");

        Array<T, N> arr2 = {1, 2, 3, 4};
        arr.swap(arr2);
        CHECK(arr[0] == 1, "Swap operation failed");
        CHECK(arr[1] == 2, "Swap operation failed");
        CHECK(arr[2] == 3, "Swap operation failed");
        CHECK(arr[3] == 4, "Swap operation failed");
    }

    static void ComparisonOperators() {
        Array<T, N> arr1 = {1, 2, 3, 4};
        Array<T, N> arr2 = {1, 2, 3, 4};
        Array<T, N> arr3 = {1, 2, 3, 5};

        CHECK(arr1 == arr2, "Equality comparison failed");
        CHECK(!(arr1 == arr3), "Inequality comparison failed");
        CHECK(arr1 <= arr2, "Less than or equal comparison failed");
        CHECK(arr1 < arr3, "Less than comparison failed");
        CHECK(arr3 > arr1, "Greater than comparison failed");
    }

    static void GetFunction() {
        Array<T, N> arr = {1, 2, 3, 4};

        CHECK(std::get<0>(arr) == 1, "Get function failed");
        CHECK(std::get<1>(arr) == 2, "Get function failed");
        CHECK(std::get<2>(arr) == 3, "Get function failed");
        CHECK(std::get<3>(arr) == 4, "Get function failed");
    }

    static void SwapFunction() {
        Array<T, N> arr1 = {1, 2, 3, 4};
        Array<T, N> arr2 = {4, 3, 2, 1};

        std::swap(arr1, arr2);

        CHECK(arr1[0] == 4, "Swap function failed");
        CHECK(arr1[1] == 3, "Swap function failed");
        CHECK(arr1[2] == 2, "Swap function failed");
        CHECK(arr1[3] == 1, "Swap function failed");

        CHECK(arr2[0] == 1, "Swap function failed");
        CHECK(arr2[1] == 2, "Swap function failed");
        CHECK(arr2[2] == 3, "Swap function failed");
        CHECK(arr2[3] == 4, "Swap function failed");
    }
};

// 测试函数
TEST(test_array) { ArrayTest<int, 4>::runTests(); }

int main() {
    test_array();
    std::cout << "All tests passed!" << std::endl;
    return 0;
}