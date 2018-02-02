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
    
    Json::Reader reader;    // 用于解析JSON的类
    Json::Value root;       // 用于储存JSON对象
    //  用reader的parse方法，传入打开的文件对象
    //  JSON中的{}对象是一个root
    if ( !reader.parse( ifs, root, false ) )
    {
        //  解析失败
        std::cout << "Parse error." << std::endl;
        exit( 1 );
    }
    //  解析成功之后，root就包含了JSON文件信息
    std::string name = root[ "name" ].asString();   //  类C/C++的map访问方式
    int age = root[ "age" ].asInt();                //  asXXX()，访问XXX类型value对象
    // 输出对应对象":"冒号之后的值
    std::cout << name << std::endl;
    std::cout << age << std::endl;
    
    return 0;
}