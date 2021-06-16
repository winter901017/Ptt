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
    vector <int> postsID;	// 紀錄建立過的post 文章
    vector <string> sender;
    vector <string> mail;
    int Permission_level;	// 權限等級
    string account;
    // Other infos, e.x. comment_nums, post_num, ….

    /* Auth: Admin, Member, Guest */
    /* level:  0       1      2   */



//-------------------------------------------------------------------------------------
/*                              更新postID									        */
//-------------------------------------------------------------------------------------
//進行讀取 在寫入 
    void updatePostsID(int newPostID)
    {
        /* 防止重複讀入 */
        postsID.clear();

        string fileName = "Log/AccountLog/" + account + "PostID.txt";
        /* 設置 file stream */
        fstream UserLog;

        /* 開啟檔案 */
        UserLog.open(fileName, std::fstream::in); //讀

        if (UserLog.is_open())
        {
            int tmpPostID;
            while (UserLog >> tmpPostID)
            {
                postsID.push_back(tmpPostID);
            }
        }

        UserLog.close();

        /* 新增postID */
        postsID.push_back(newPostID);

        /* 重寫回去 */
        fileName = "Log/AccountLog/" + account + "PostID.txt";

        UserLog.open(fileName, std::fstream::out); //添加

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

