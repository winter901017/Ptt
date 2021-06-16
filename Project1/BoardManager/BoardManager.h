#pragma once
#ifndef BOARDMANAGER_H
#define BOARDMANAGER_H

#include "../User/User.h"
#include "../User/Admin.h"
#include "../User/Member.h"
#include "../User/Guest.h"
#include "../Viewer/Viwer.h"
#include "../Board/Board.h"
#include <vector>
#include <string>
using namespace std;

enum BoardState
{
    MENU,
    SELECT_BOARD,
    BOARD,
    POST
};
class BoardManager
{
public:
    vector <User*> users;
    vector <Board> boards;
    int current_user = -1;
    int current_boards = 0;
    int current_post = 0; 
    BoardState state;
    Viewer viewer;


//-------------------------------------------------------------------------------------
/*                              �إ߱b��                                             */
//-------------------------------------------------------------------------------------
// 
// ��Ʈ榡: permisson_level, account, passwd
// permison_level : �b���v��
// account : �b��
// passwd : �K�X

    /* �Х߱b���ɭn�إ�log�B�ݧP�_�b���w�g�O�_�s�b */
    bool create_Account(string account, string passwd)
    {
        /* �]�ɦW User�b�����ɮצW�� �b��.txt*/
        string fileName = "Log/AccountLog/" + account + ".txt";

        /* �]�m file stream */
        fstream UserLog;

        /* �}���ɮ� */
        UserLog.open(fileName);

      
        /* �s�b���ܴN�ХL��J�O�o�b�� */
        if (UserLog.is_open())
        {
            /* �����ɮ� */
            UserLog.close();
            /* �^�ǫإߥ��� ��ܤw�s�b */
            return false;
        }
        /* ���s�b�N�إ߱b�� */
        else
        {
           /* �}���ɮ� �]�w�g�J�Ҧ� */
           UserLog.open(fileName, ios_base::app);
           /* �i��g�J */
           UserLog << 1 << ' ' << account << ' ' << passwd << '\n';
           /* �����ɮ� */
           UserLog.close();
           /* �^�ǫإߦ��\ */
           return true;
        };

    }

//-------------------------------------------------------------------------------------
/*                             �n�J�b��                                              */
//-------------------------------------------------------------------------------------
// �ǤJ�b���K�X ��LogUser��Ƨ���account.txt �䤣��^��false 
// ��쪺�� �N�NpostsID�ǤJ
// �^�� 0 ��ܱK�X���T
// �^�� 1 ��ܱK�X���~
// �^�� 2 ��ܧ䤣��b�� 
    int login(string account, string passwd)
    {
        /* �]�ɦW User�b�����ɮצW�� �b��.txt*/
        string fileName = "Log/AccountLog/" + account + ".txt";

        /* �]�m file stream */
        fstream UserLog;

        /* �}���ɮ� */
        UserLog.open(fileName);

        if (UserLog.is_open()) {
            string clean,txtPasswd;
            while (UserLog >> clean >> clean >> txtPasswd) // clean�O���Ϊ�string
            {
                if (passwd == txtPasswd) // ²��P�_ �K�X�O�_���T
                {
                    return 0;
                }
            }
            return 1;
        }

        return 2;
    }

//-------------------------------------------------------------------------------------
/*                             �ϥΪ��v���d��                                        */
//-------------------------------------------------------------------------------------
// �^�� 0 admin�v��
// �^�� 1 ���q�|��
// �^�� 2 �X��
    string searchPermissionLevel(string account)
    {
        /* �]�ɦW User�b�����ɮצW�� �b��.txt*/
        string fileName = "Log/AccountLog/" + account + ".txt";

        /* �]�m file stream */
        fstream UserLog;

        /* �}���ɮ� */
        UserLog.open(fileName);

        if (UserLog.is_open()) {
            string level,clean;
            while (UserLog >> level >> clean >> clean) // clean�O���Ϊ�string
            {
                return level;
            }
            return level;
        }
    }

//-------------------------------------------------------------------------------------
/*                             ����post��X�� �B�^�ǥi�H�ϥΪ�postID                 */
//-------------------------------------------------------------------------------------
//��Ū�ɮ� �A���s�g�J
//�^�Ƿs�峹�i�H�Ϊ�PostID
    int getPostID()
    {
        //�d�ݲ{�b��post�O����X��
        string fileName = "Log/BoardManagerLog/currentPostID.txt";

        /* �]�m file stream */
        fstream UserLog;

        /* �}���ɮ� */
        UserLog.open(fileName, std::fstream::in); //Ū���Ҧ� 


        int postID = 0;

        /* ��Ū�� */
        if (UserLog.is_open())
        {
            UserLog >> postID;
        }

        UserLog.close();

        UserLog.open(fileName, std::fstream::out); //�g�J�Ҧ�

        if (UserLog.is_open())
        {
            UserLog << (postID + 1); // �[�@��
        }

        UserLog.close();

        return postID + 1;
    }

};
#endif // !BOARDMANAGER_H
