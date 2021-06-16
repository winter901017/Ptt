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
        return "�@";
        break;
    case 2:
        return "�G";
        break;
    case 3:
        return "�T";
        break;
    case 4:
        return "�|";
        break;
    case 5:
        return "��";
        break;
    case 6:
        return "��";
        break;
    case 7:
        return "��";
        break;
    }
    return to_string(a);
}

class Board
{
public:
	string ID; // ���OID
	string title; // ���O���e
    vector <string> classficaitonBoard;
    vector<int> postID; // �����إ߹L��post �峹

//-------------------------------------------------------------------------------------
/*                                  �ūغc�l     			                         */
//-------------------------------------------------------------------------------------
	Board()
	{

	}

//-------------------------------------------------------------------------------------
/*                              �غc�l ���Φr��B�g�ɮ�    			                 */
//-------------------------------------------------------------------------------------
	Board(string writeTxt)
	{
		/* �r����� */
        for (int i = 0; i < writeTxt.size(); i++)
        {
            if (writeTxt[i] == ' ')
            {
                ID = writeTxt.substr(0, i );
                title = writeTxt.substr(i, writeTxt.size());
                break;
            }
        }

        /* �]�ɦW Board���ɮצW�� ID + .txt */
        string fileName = "Log/BoardLog/Board.txt";

        /* �]�m file stream */
        fstream UserLog;

        /* �}���ɮ� */
        UserLog.open(fileName, std::fstream::in | std::fstream::out | std::fstream::app); //Ū���Ҧ� �g�J�Ҧ� �K�[�Ҧ�

        /* �P�_�O�_�i�H�}�� */
        if (UserLog.is_open()) //�}�Ҧ��\�NŪ�ɮ�
        {
            /* �g�J���W */
            UserLog << ID << title << '\n';
        }

        /* �����ɮ� */
        UserLog.close();
        /* �^�ǫإߦ��\ */
   
	}

//-------------------------------------------------------------------------------------
/*                             �غc�l �ϥΦbŪ��ID title �إ�Class				     */
//-------------------------------------------------------------------------------------
    /* �ϥΦbŪ��ID title �إ�Class */
    Board(string copyID, string copyTitle)
    { 
        ID = copyID;
        title = copyTitle;
    }

//-------------------------------------------------------------------------------------
/*                             �إߤ峹�B�g��				                         */
//-------------------------------------------------------------------------------------
//�إ�postID.txt�����e�A��ݪO��postID�W�[postID
    void createPost(int newPostID, string newTitle, string newContent,string auth)
    {
        /* ���إ�post����� */

        /* �]�ɦW Board���ɮצW�� PostID.txt */
        string fileName = "Log/PostsIDLog/" + to_string(newPostID) + ".txt";

        /* �]�m file stream */
        fstream UserLog;

        /* �}���ɮ� */
        UserLog.open(fileName, std::fstream::in | std::fstream::out | std::fstream::app); //Ū���Ҧ� �g�J�Ҧ� �K�[�Ҧ�

        /* ����ɶ� */
        SYSTEMTIME sys;
        GetLocalTime(&sys);

        // sys.wYear,sys.wMonth,sys.wDay,sys.wHour,sys.wMinute, sys.wSecond,sys.wMilliseconds,sys.wDayOfWeek

        UserLog << 0 << "\n"; //good
        UserLog << 0 << "\n"; //bad
        UserLog << "�P��" << weekToStr(sys.wDayOfWeek) << " ";
        UserLog << timeToStr(sys.wMonth) << "/";
        UserLog << timeToStr(sys.wDay) << " ";
        UserLog << timeToStr(sys.wHour) << ":" << timeToStr(sys.wMinute) << ":" << timeToStr(sys.wSecond) << " ";
        UserLog << sys.wYear << "\n";
        UserLog << auth << "\n";
        UserLog <<  newTitle << '\n';
 
        UserLog.close();

        fileName = "Log/PostsIDLog/" + to_string(newPostID) + "Content.txt";
        UserLog.open(fileName, std::fstream::in | std::fstream::out | std::fstream::app); //Ū���Ҧ� �g�J�Ҧ� �K�[�Ҧ�
        UserLog << newContent << '\n';
        UserLog.close();

        fileName = "Log/PostsIDLog/" + to_string(newPostID) + "Command.txt";
        UserLog.open(fileName, std::fstream::in | std::fstream::out | std::fstream::app); //Ū���Ҧ� �g�J�Ҧ� �K�[�Ҧ�
        UserLog.close();

        fileName = "Log/PostsIDLog/" + to_string(newPostID) + "RecodePress.txt";
        UserLog.open(fileName, std::fstream::in | std::fstream::out | std::fstream::app); //Ū���Ҧ� �g�J�Ҧ� �K�[�Ҧ�
        UserLog.close();


        /* �]�ɦW Board���ɮצW�� Board.txt */
        fileName = "Log/BoardLog/" + title + "Board.txt";

        /* �}���ɮ� */
        UserLog.open(fileName,std::fstream::app); // �K�[�Ҧ�

        /* �s�WpostID ��ݪO */
        UserLog << newPostID << '\n';

        /* �����ɮ� */
        UserLog.close();
    }
};


#endif // !BOARD_H

