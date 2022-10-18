#ifndef TOOLS_H
#define TOOLS_H

#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <fstream>
#include <unistd.h>

using namespace std;

#define DATA_ID_PATH "./data/id.dat"
#define DATA_MGR_PATH "./data/managers.dat"
#define DATA_SRC_PATH "./data/services.dat"

//从键盘获取字符串
char* get_str(char* str,size_t len);
//从键盘获取密码
char* get_pass(char* pass,size_t len,bool is_show=false);
int get_cmd(char start,char end);
void anykey_continue(void);

//初始化id.dat文件
void init_id(void);
//生成唯一的管理员id号
int get_mgrid(void);
//生成唯一的部门id号
int get_depid(void);
//生成唯一的员工id号
int get_empid(void);

#endif//TOOLS_H
