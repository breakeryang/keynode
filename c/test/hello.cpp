
// g++ hello.cpp -lcrypto
#include <iostream>
#include <string>
#include <cstring>
#include <cassert>

#include <openssl/rsa.h>
#include <openssl/err.h>
#include <openssl/pem.h>


using namespace std;

class Box {
    public:
        double length;
        double height;
        double width; // 宽

        double getVolume(){
            return height * length * width;
        }
};

std::string EncodeRSAKeyFile(const std::string& strPemFileName, const std::string& strData){
    if (strPemFileName.empty() || strData.empty()){
        assert(false) ;
        return "";
    }


    FILE* hPubKeyFile = fopen(strPemFileName.c_str(), "rb");

    if (hPubKeyFile == NULL){
        assert(false);
        return "";
    }

    str::string strRet;

    RSA* pRSAPublicKey = RSA_new();

    if (PEM_read_RSA_PUBKEY(hPubKeyFile, &pRSAPublicKey, 0, 0) == NULL){
        assert(false);
        return "";
    }

    int nLen = RSA_size(pRSAPublicKey);
    char* pEncode = new char[nLen + 1];
    int ret = RSA_public_encrypt(strData.length(), (const unsigned char*)strData.c_str(), (unsigned char*)pEncode, pRSAPublicKey, RSA_PKCS1_PADDING);
    if (ret >= 0)
    {
    strRet = std::string(pEncode, ret);

    }
    delete[] pEncode;
    RSA_free(pRSAPublicKey);
    fclose(hPubKeyFile);
    CRYPTO_cleanup_all_ex_data();
    return strRet;


}

int main(int argc, char * argv[]){
    cout << "Hello C++!" << endl;

    Box box1;
    Box box2;

    double height = 10.0;

    box1.height = 5.0;
    box1.length = 2.0;
    box1.width = 10.0;

    height = box1.height * box1.length * box1.width;

    cout << "Volume of box1 : " << height
        << " - " << box1.getVolume()
        << endl;


    return 0;
}



