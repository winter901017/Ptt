#pragma once
#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <vector>
#include <windows.h>
#include <stdio.h>

using namespace std;

string timeToStr(int a) 
{
    switch (a)
    {
    case 0:
        return "00";
        break;
    case 1:
        return "01";
        break;
    case 2:
        return "02";
        break;
    case 3:
        return "03";
        break;
    case 4:
        return "04";
        break;
    case 5:
        return "05";
        break;
    case 6:
        return "06";
        break;
    case 7:
        return "07";
        break;
    case 8:
        return "08";
        break;
    case 9:
        return "09";
        break;
    }
    return to_string(a);
}
string weekToStr(int a)
{
    switch (a)
    {
    case 1:
        return "一";
        break;
    case 2:
        return "二";
        break;
    case 3:
        return "三";
        break;
    case 4:
        return "四";
        break;
    case 5:
        return "五";
        break;
    case 6:
        return "六";
        break;
    case 7:
        return "日";
        break;
    }
    return to_string(a);
}

class Board
{
public:
	string ID; // 面板ID
	string title; // 面板內容
    vector <string> classficaitonBoard;
    vector<int> postID; // 紀錄建立過的post 文章

//-------------------------------------------------------------------------------------
/*                                  空建構子     			                         */
//-------------------------------------------------------------------------------------
	Board()
	{

	}

//-------------------------------------------------------------------------------------
/*                              建構子 分割字串且寫檔案    			                 */
//-------------------------------------------------------------------------------------
	Board(string writeTxt)
	{
		/* 字串分割 */
        for (int i = 0; i < writeTxt.size(); i++)
        {
            if (writeTxt[i] == ' ')
            {
                ID = writeTxt.substr(0, i );
                title = writeTxt.substr(i, writeTxt.size());
                break;
            }
        }

        /* 設檔名 Board的檔案名為 ID + .txt */
        string fileName = "Log/BoardLog/Board.txt";

        /* 設置 file stream */
        fstream UserLog;

        /* 開啟檔案 */
        UserLog.open(fileName, std::fstream::in | std::fstream::out | std::fstream::app); //讀取模式 寫入模式 添加模式

        /* 判斷是否可以開啟 */
        if (UserLog.is_open()) //開啟成功就讀檔案
        {
            /* 寫入版名 */
            UserLog << ID << title << '\n';
        }

        /* 關閉檔案 */
        UserLog.close();
        /* 回傳建立成功 */
   
	}

//-------------------------------------------------------------------------------------
/*                             建構子 使用在讀取ID title 建立Class				     */
//-------------------------------------------------------------------------------------
    /* 使用在讀取ID title 建立Class */
    Board(string copyID, string copyTitle)
    { 
        ID = copyID;
        title = copyTitle;
    }

//-------------------------------------------------------------------------------------
/*                             建立文章且寫檔				                         */
//-------------------------------------------------------------------------------------
//建立postID.txt的內容再到看板的postID增加postID
    void createPost(int newPostID, string newTitle, string newContent,string auth)
    {
        /* 先建立post的資料 */

        /* 設檔名 Board的檔案名為 PostID.txt */
        string fileName = "Log/PostsIDLog/" + to_string(newPostID) + ".txt";

        /* 設置 file stream */
        fstream UserLog;

        /* 開啟檔案 */
        UserLog.open(fileName, std::fstream::in | std::fstream::out | std::fstream::app); //讀取模式 寫入模式 添加模式

        /* 抓取時間 */
        SYSTEMTIME sys;
        GetLocalTime(&sys);

        // sys.wYear,sys.wMonth,sys.wDay,sys.wHour,sys.wMinute, sys.wSecond,sys.wMilliseconds,sys.wDayOfWeek

        UserLog << 0 << "\n"; //good
        UserLog << 0 << "\n"; //bad
        UserLog << "星期" << weekToStr(sys.wDayOfWeek) << " ";
        UserLog << timeToStr(sys.wMonth) << "/";
        UserLog << timeToStr(sys.wDay) << " ";
        UserLog << timeToStr(sys.wHour) << ":" << timeToStr(sys.wMinute) << ":" << timeToStr(sys.wSecond) << " ";
        UserLog << sys.wYear << "\n";
        UserLog << auth << "\n";
        UserLog <<  newTitle << '\n';
 
        UserLog.close();

        fileName = "Log/PostsIDLog/" + to_string(newPostID) + "Content.txt";
        UserLog.open(fileName, std::fstream::in | std::fstream::out | std::fstream::app); //讀取模式 寫入模式 添加模式
        UserLog << newContent << '\n';
        UserLog.close();

        fileName = "Log/PostsIDLog/" + to_string(newPostID) + "Command.txt";
        UserLog.open(fileName, std::fstream::in | std::fstream::out | std::fstream::app); //讀取模式 寫入模式 添加模式
        UserLog.close();

        fileName = "Log/PostsIDLog/" + to_string(newPostID) + "RecodePress.txt";
        UserLog.open(fileName, std::fstream::in | std::fstream::out | std::fstream::app); //讀取模式 寫入模式 添加模式
        UserLog.close();


        /* 設檔名 Board的檔案名為 Board.txt */
        fileName = "Log/BoardLog/" + title + "Board.txt";

        /* 開啟檔案 */
        UserLog.open(fileName,std::fstream::app); // 添加模式

        /* 新增postID 到看板 */
        UserLog << newPostID << '\n';

        /* 關閉檔案 */
        UserLog.close();
    }
};


#endif // !BOARD_H

