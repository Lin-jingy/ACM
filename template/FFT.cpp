#include <bits/stdc++.h>

double Pi = std::acos(-1);

class FFT {
private:
    int n;
public:
    FFT(int N):n(N) {

    }
    void dft(std::vector<std::complex<int>>::iterator begin, int len) {
        if(len == 1) return ;
        auto fl= begin, fr=begin + len / 2;
        auto save = 
        for (int k=0;k<len;k++)sav[k]=f[k];
        for (int k=0;k<len/2;k++)//分奇偶打乱
            {fl[k]=sav[k<<1];fr[k]=sav[k<<1|1];}
        dft(fl,len/2);
        dft(fr,len/2);//处理子问题
        //由于每次使用的单位根次数不同(len次单位根),所以要重新求。
        CP tG(cos(2*Pi/len),sin(2*Pi/len)),buf(1,0);
        for (int k=0;k<len/2;k++){
            //这里buf = (len次单位根的第k个) 
            sav[k]=fl[k]+buf*fr[k];//(1)
            sav[k+len/2]=fl[k]-buf*fr[k];//(2)
            //这两条语句具体见Tips的式子
            buf=buf*tG;//得到下一个单位根。
        }for (int k=0;k<len;k++)f[k]=sav[k];
    }
    void fft() {

    }
    void idft() {

    }
};