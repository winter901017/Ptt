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
/*                              建立帳戶                                             */
//-------------------------------------------------------------------------------------
// 
// 資料格式: permisson_level, account, passwd
// permison_level : 帳號權限
// account : 帳號
// passwd : 密碼

    /* 創立帳號時要建立log且需判斷帳號已經是否存在 */
    bool create_Account(string account, string passwd)
    {
        /* 設檔名 User帳號的檔案名為 帳號.txt*/
        string fileName = "Log/AccountLog/" + account + ".txt";

        /* 設置 file stream */
        fstream UserLog;

        /* 開啟檔案 */
        UserLog.open(fileName);

      
        /* 存在的話就請他輸入別得帳號 */
        if (UserLog.is_open())
        {
            /* 關閉檔案 */
            UserLog.close();
            /* 回傳建立失敗 表示已存在 */
            return false;
        }
        /* 不存在就建立帳號 */
        else
        {
           /* 開啟檔案 設定寫入模式 */
           UserLog.open(fileName, ios_base::app);
           /* 進行寫入 */
           UserLog << 1 << ' ' << account << ' ' << passwd << '\n';
           /* 關閉檔案 */
           UserLog.close();
           /* 回傳建立成功 */
           return true;
        };

    }

//-------------------------------------------------------------------------------------
/*                             登入帳號                                              */
//-------------------------------------------------------------------------------------
// 傳入帳號密碼 對LogUser資料夾找account.txt 找不到回傳false 
// 找到的話 就將postsID傳入
// 回傳 0 表示密碼正確
// 回傳 1 表示密碼錯誤
// 回傳 2 表示找不到帳號 
    int login(string account, string passwd)
    {
        /* 設檔名 User帳號的檔案名為 帳號.txt*/
        string fileName = "Log/AccountLog/" + account + ".txt";

        /* 設置 file stream */
        fstream UserLog;

        /* 開啟檔案 */
        UserLog.open(fileName);

        if (UserLog.is_open()) {
            string clean,txtPasswd;
            while (UserLog >> clean >> clean >> txtPasswd) // clean是不用的string
            {
                if (passwd == txtPasswd) // 簡單判斷 密碼是否正確
                {
                    return 0;
                }
            }
            return 1;
        }

        return 2;
    }

//-------------------------------------------------------------------------------------
/*                             使用者權限查詢                                        */
//-------------------------------------------------------------------------------------
// 回傳 0 admin權限
// 回傳 1 普通會員
// 回傳 2 訪客
    string searchPermissionLevel(string account)
    {
        /* 設檔名 User帳號的檔案名為 帳號.txt*/
        string fileName = "Log/AccountLog/" + account + ".txt";

        /* 設置 file stream */
        fstream UserLog;

        /* 開啟檔案 */
        UserLog.open(fileName);

        if (UserLog.is_open()) {
            string level,clean;
            while (UserLog >> level >> clean >> clean) // clean是不用的string
            {
                return level;
            }
            return level;
        }
    }

//-------------------------------------------------------------------------------------
/*                             紀錄post到幾號 且回傳可以使用的postID                 */
//-------------------------------------------------------------------------------------
//先讀檔案 再重新寫入
//回傳新文章可以用的PostID
    int getPostID()
    {
        //查看現在的post記錄到幾號
        string fileName = "Log/BoardManagerLog/currentPostID.txt";

        /* 設置 file stream */
        fstream UserLog;

        /* 開啟檔案 */
        UserLog.open(fileName, std::fstream::in); //讀取模式 


        int postID = 0;

        /* 先讀檔 */
        if (UserLog.is_open())
        {
            UserLog >> postID;
        }

        UserLog.close();

        UserLog.open(fileName, std::fstream::out); //寫入模式

        if (UserLog.is_open())
        {
            UserLog << (postID + 1); // 加一號
        }

        UserLog.close();

        return postID + 1;
    }

};
#endif // !BOARDMANAGER_H
