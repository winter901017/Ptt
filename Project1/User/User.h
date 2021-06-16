#pragma once
#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

class User
{
public:
    vector <int> postsID;	// �����إ߹L��post �峹
    vector <string> sender;
    vector <string> mail;
    int Permission_level;	// �v������
    string account;
    // Other infos, e.x. comment_nums, post_num, �K.

    /* Auth: Admin, Member, Guest */
    /* level:  0       1      2   */



//-------------------------------------------------------------------------------------
/*                              ��spostID									        */
//-------------------------------------------------------------------------------------
//�i��Ū�� �b�g�J 
    void updatePostsID(int newPostID)
    {
        /* �����Ū�J */
        postsID.clear();

        string fileName = "Log/AccountLog/" + account + "PostID.txt";
        /* �]�m file stream */
        fstream UserLog;

        /* �}���ɮ� */
        UserLog.open(fileName, std::fstream::in); //Ū

        if (UserLog.is_open())
        {
            int tmpPostID;
            while (UserLog >> tmpPostID)
            {
                postsID.push_back(tmpPostID);
            }
        }

        UserLog.close();

        /* �s�WpostID */
        postsID.push_back(newPostID);

        /* ���g�^�h */
        fileName = "Log/AccountLog/" + account + "PostID.txt";

        UserLog.open(fileName, std::fstream::out); //�K�[

        if (UserLog.is_open())
        {
            if (!postsID.empty())
            {
                for (int i = 0; i < postsID.size(); i++)
                {
                    UserLog << postsID[i] << '\n';
                }
            }
        }

        UserLog.close();
    }

};


#endif // !USER_H

