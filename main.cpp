#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
// S-DES FUNCTIONS
const int ip[8] = {1,5,2,0,3,7,4,6};
const int ip_1[8] = {3,0,2,4,6,1,7,5};
const int p10[10] = {2,4,1,6,3,9,0,8,7,5};
const int p8[8] = {5,2,6,3,7,4,9,8};
const int ep[8] = {3,0,1,2,1,2,3,0};
const int p4[4] = {1,3,2,0};
const int s0[4][4] = {{1,0,3,2},
                      {3,2,1,0},
                      {0,2,1,3},
                      {3,1,3,2}};
const int s1[4][4] = {{0,1,2,3},
                      {2,0,1,3},
                      {3,0,1,0},
                      {2,1,0,3}};
vector<int> key1(8);
vector<int> key2(8);

// CALCULATION FUNCTIONS
void permute(vector<int> &, vector<int> &, const int []);
void half(vector<int> &, vector<int> &, vector<int> &);
void leftShift(vector<int> &, vector<int> &);
void joinHalves(vector<int> &, vector<int> &, vector<int> &);
vector<int> XOR(vector<int>, vector<int>);
vector<int> sFunction(const int s[4][4], vector<int> &in);
void computeKeys();
vector<int> encrypt();
vector<int> decrypt();

int main() {
    vector<int> output(8);
    int choice = 1;

    while (choice != 0) {
        cout << "Would you like to (1) encrypt or (2) decrypt a message? (press 0 to end program) " << endl;
        cin >> choice;

        switch (choice) {
            default:
                cout << "No valid option was chosen. Exiting program.";
                break;
            case 0:
                cout << "Program ending.";
                return 0;
            case 1:
                output = encrypt();
                cout << "Encrypted text is:\n";
                for (auto x: output){
                    cout << x;
                }
                cout << "\n\n";
                break;
            case 2:
                output = decrypt();
                cout << "Decrypted text is:\n";
                for (auto x: output){
                    cout << x;
                }
                cout << "\n\n";
                break;
        }
    }

    return 0;
}

void permute(vector<int> &output, vector<int> &input, const int perm[]){
    for(int i=0; i<output.size(); ++i) {
        output[i]=(input[perm[i]]);
    }
}
void half(vector<int> &vec, vector<int> &l, vector<int> &r){
    vector<int>::iterator it;
    for (it = vec.begin(); it != vec.end(); it++){
        if(it-vec.begin() < vec.size()/2){
            l[it-vec.begin()]=(*it);
        }
        else{
            r[it-vec.begin() - r.capacity()]=(*it);
        }
    }
}
void leftShift(vector<int> &l, vector<int> &r){
    int t, i;

    t = l[0];
    for (i=0;i<l.size()-1; i++){
        l[i] = l[i+1];
    }
    l[l.size()-1] = t;

    t = r[0];
    for (i=0;i<r.size()-1; i++){
        r[i] = r[i+1];
    }
    r[r.size()-1] = t;
}
void joinHalves(vector<int> &temp, vector<int> &l, vector<int> &r){
    for (int i=0;i<temp.size();i++){
        if (i<l.size()) {
            temp[i] = l[i];
        }
        else
            temp[i] = r[i-r.size()];
    }
}
vector<int> XOR(vector<int> a, vector<int> b){
    vector<int> temp;
    for(int i=0; i<a.size(); i++){
        if(a[i] == b[i]){
            temp.push_back(0);
        }
        else
            temp.push_back(1);
    }
    return temp;
}
vector<int> sFunction(const int s[4][4], vector<int> &in){
    int a, b, x = 0, y = 0, result;
    vector<int> output(2);
    a = in[0]; b = in[in.size()-1];
    if(a == 0 && b == 0){
        x = 0;
    }
    else if(a == 1 && b == 1){
        x = 3;
    }
    else if( a == 1 && b == 0){
        x = 2;
    }
    else if (a == 0 && b == 1){
        x = 1;
    }
    a = in[1]; b = in[in.size()-2];
    if(a == 0 && b == 0){
        y = 0;
    }
    else if(a == 1 && b == 1){
        y = 3;
    }
    else if( a == 1 && b == 0){
        y = 2;
    }
    else if (a == 0 && b == 1){
        y = 1;
    }
    result = s[x][y];
    if(result == 3){
        output = {1,1};
    }
    else if(result == 2){
        output = {1,0};
    }
    else if (result == 1){
        output = {0,1};
    }
    else if (result == 0){
        output = {0,0};
    }
    return output;
}
void computeKeys(){
    vector<int> temp(10), lHalf(5), rHalf(5);
    char keyIn[11];
    vector<int> kIn(10);

    cin.ignore();
    cout<< "Enter 10 bit key:\n";
    cin.getline(keyIn, 11);
    for(int i=0; i<10;i++){
        kIn[i]=keyIn[i]-48;
    }

    permute(temp, kIn, p10);
    half(temp, lHalf, rHalf);
    leftShift(lHalf, rHalf);
    joinHalves(temp, lHalf, rHalf);
    permute(key1, temp, p8);
    leftShift(lHalf, rHalf);
    leftShift(lHalf, rHalf);
    joinHalves(temp, lHalf, rHalf);
    permute(key2, temp, p8);

    cout << "The keys are:\n";
    for (auto x: key1){
        cout << x;
    }
    cout << endl;
    for (auto y: key2){
        cout << y;
    }
    cout << endl;
}
vector<int> encrypt(){
    vector<int> temp(8), output(8);
    vector<int> lHalf(4), rHalf(4), sOut(4);
    vector<int> lcopy, rcopy;
    vector<int> s0out(2), s1out(2);
    vector<int> pt(8);
    char plainText[9];
    int i;

    computeKeys();
    cout<< "Enter 8 bit plaintext to encrypt:\n";
    cin.getline(plainText, 9);
    for(int i=0; i<8;i++){
        pt[i]=plainText[i]-48;
    }

    permute(temp, pt, ip);
    half(temp, lHalf, rHalf);
    lcopy = lHalf; rcopy = rHalf;
    permute(temp, rHalf, ep);
    temp = XOR(temp, key1);
    half(temp, lHalf, rHalf);
    s0out = sFunction(s0, lHalf);
    s1out = sFunction(s1, rHalf);
    joinHalves(rHalf,s0out, s1out);
    permute(sOut, rHalf, p4);
    sOut = XOR(sOut,lcopy);
    rHalf = sOut;
    lHalf = rcopy;
    lcopy = lHalf; rcopy = rHalf;
    permute(temp, rHalf, ep);
    temp = XOR(temp, key2);
    half(temp, lHalf, rHalf);
    s0out = sFunction(s0, lHalf);
    s1out = sFunction(s1, rHalf);
    joinHalves(rHalf,s0out, s1out);
    permute(sOut, rHalf, p4);
    sOut = XOR(sOut,lcopy);
    joinHalves(temp, sOut, rcopy);
    permute(output, temp, ip_1);

    return output;
}
vector<int> decrypt(){
    vector<int> temp(8), output(8);
    vector<int> lHalf(4), rHalf(4), sOut(4);
    vector<int> lcopy, rcopy;
    vector<int> s0out(2), s1out(2);
    vector<int> ct(8);
    char cipherText[9];
    int i;

    computeKeys();
    cout<< "Enter 8 bit ciphertext to decrypt:\n";
    cin.getline(cipherText, 9);
    for(int i=0; i<8;i++){
        ct[i]=cipherText[i]-48;
    }

    permute(temp, ct, ip);
    half(temp, lHalf, rHalf);
    lcopy = lHalf; rcopy = rHalf;
    permute(temp, rHalf, ep);
    temp = XOR(temp, key2);
    half(temp, lHalf, rHalf);
    s0out = sFunction(s0, lHalf);
    s1out = sFunction(s1, rHalf);
    joinHalves(rHalf,s0out, s1out);
    permute(sOut, rHalf, p4);
    sOut = XOR(sOut,lcopy);
    rHalf = sOut;
    lHalf = rcopy;
    lcopy = lHalf; rcopy = rHalf;
    permute(temp, rHalf, ep);
    temp = XOR(temp, key1);
    half(temp, lHalf, rHalf);
    s0out = sFunction(s0, lHalf);
    s1out = sFunction(s1, rHalf);
    joinHalves(rHalf,s0out, s1out);
    permute(sOut, rHalf, p4);
    sOut = XOR(sOut,lcopy);
    joinHalves(temp, sOut, rcopy);
    permute(output, temp, ip_1);

    return output;
}