/* *** ������д���˿���˳���û���ִ�� ***
 * ***  ��Զ��Ҫ�����κδ������Ĳ��� ***
 * 
 * �ļ�: question_01.hpp
 * ʱ��: 2020/4/15-20:06
 * ����: Pip
 */

#include <bits/stdc++.h>

using namespace std;

class CMyString {
public:
    CMyString(const char *mData = nullptr) {
        int size = mData == nullptr ? 1 : strlen(mData) + 1;
        char *temp = new char[size];
        if(mData != nullptr) {
            strcpy(temp, mData);
        }
        this->m_data = temp;
    }

    CMyString(const CMyString &str) {
        char *temp = new char[strlen(str.m_data) + 1];
        strcpy(temp, str.m_data);
        this->m_data = temp;
    }

    CMyString &operator=(const CMyString &str) {
        // �ж��Ƿ����Ը�ֵ
        if (&str != this) {
            // ��ʱ����
            CMyString tempStr(str);

            // ����ʱ����͵�ǰ�����ʵ�����н�������ʱ��������ʱҲ���ͷ���Դ
            std::swap(this->m_data, tempStr.m_data);
        }

        // ��ʽ���������ֵ
        return *this;
    }

    friend ostream &operator<<(ostream &out, const CMyString & str) {
        out << &str.m_data << ":" <<  str.m_data;
        return out;
    }

    virtual ~CMyString() {
        if (nullptr != this->m_data) {
            delete[] this->m_data;
        }

    }

private:
    char *m_data;
};

int test() {
    // ����
    CMyString c1("hello c1");
    CMyString c2;
    CMyString c3;
    CMyString c4;

    // ���Դ�ӡ����
    cout << "c1:" <<c1 << endl;

    // ��һ��ʵ����ֵ����һ��ʵ��
    c2 = c1;
    cout << "c1:" << c1 << endl;
    cout << "c2:" << c2 << endl;

    // ��ֵ���Լ�
    c1 = c1;
    cout << "c1:" << c1 << endl;

    // ������ֵ
    c4 = c3 = c2 = c1;

    cout << "c1:" << c1 << endl;
    cout << "c2:" << c2 << endl;
    cout << "c3:" << c3 << endl;
    cout << "c4:" << c4 << endl;

    return 0;
}