#pragma warning(disable:4996)
#pragma comment(lib, "lib_json.lib")

#include <fstream>
#include <cassert>
#include "json.h"
#include <iostream>

using namespace std;

int main()
{
    ifstream ifs;
    ifs.open( "F:\\Github\\jsoncpp_template\\test.json",ios::binary|ios::in );
    assert( ifs.is_open() );
    
    Json::Reader reader;    // ���ڽ���JSON����
    Json::Value root;       // ���ڴ���JSON����
    //  ��reader��parse����������򿪵��ļ�����
    //  JSON�е�{}������һ��root
    if ( !reader.parse( ifs, root, false ) )
    {
        //  ����ʧ��
        std::cout << "Parse error." << std::endl;
        exit( 1 );
    }
    //  �����ɹ�֮��root�Ͱ�����JSON�ļ���Ϣ
    std::string name = root[ "name" ].asString();   //  ��C/C++��map���ʷ�ʽ
    int age = root[ "age" ].asInt();                //  asXXX()������XXX����value����
    // �����Ӧ����":"ð��֮���ֵ
    std::cout << name << std::endl;
    std::cout << age << std::endl;
    
    return 0;
}