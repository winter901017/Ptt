/*顯示*/
#pragma once
#ifndef VIEWER_H
#define VIEWER_H

#include "../Board/Board.h"

#include <iostream>
#include <string>
#include<windows.h>
#include<winusb.h>
#include <cwchar>
#include <math.h>
#include <ctime>
#include <conio.h>  /*  _getch() */
#include <iomanip> 
using namespace std;


/* 設置文字顏色 */
/* 119 淺灰色 lightGray */
/* 136 深灰色 darkGray */
/* 255 白色 white */
/*   7 黑色 black */
const int LIGHTGRAY = 119;
const int DARKGRAY = 136;
const int WHITE = 255;
const int BLACK = 15;
const int DARKBLUE = 31;
const int GRAY = 127;

struct position
{
	int y;
	int x;
};

class Viewer
{
public:

	COORD cursorPosition;// 現在光標的位置

	//-------------------------------------------------------------------------------------
	/*                              一開始進來的時候介面 單純顯示						 */
	//-------------------------------------------------------------------------------------

		/* 顯示標題 */
	void showTitle()
	{
		/* 重複卡在這裡直到正確或是離開 */
		ios_base::sync_with_stdio(false); /* 加速cout */
		cin.tie(NULL); /* 加速cout */

		cout << "｜ #######    #####    #######     ##    ##    ## ######## ##     ##  ######  ########    ########  ########  ########｜\n";
		cout << "｜##     ##  ##   ##  ##     ##  ####    ###   ##    ##    ##     ## ##    ##    ##       ##     ## ##     ##    ##   ｜\n";
		cout << "｜       ## ##     ##        ##    ##    ####  ##    ##    ##     ## ##          ##       ##     ## ##     ##    ##   ｜\n";
		cout << "｜ #######  ##     ##  #######     ##    ## ## ##    ##    ##     ##  ######     ##       ########  ########     ##   ｜\n";
		cout << "｜##        ##     ## ##           ##    ##  ####    ##    ##     ##       ##    ##       ##        ##           ##   ｜\n";
		cout << "｜##         ##   ##  ##           ##    ##   ###    ##    ##     ## ##    ##    ##       ##        ##           ##   ｜\n";
		cout << "｜#########   #####   #########  ######  ##    ##    ##     #######   ######     ##       ##        ##           ##   ｜\n";
	}

	//-------------------------------------------------------------------------------------
	/*                              一開始的menu的文字									 */
	//-------------------------------------------------------------------------------------

		/* 請輸入new註冊或是guest訪客登入或是輸入帳號: */
	void showAccount_or_Register()
	{
		HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD position;    // position 是一個 COORD 結構
		position.X = 5; //設定列在螢幕中心附近
		position.Y = 20; //設定行在螢幕中心附近
		SetConsoleCursorPosition(screen, position); //設置
		cout << "請輸入new註冊或是guest訪客登入或是輸入帳號：";
	}

	//-------------------------------------------------------------------------------------
	/*                              當輸入帳號後跳出的文字								 */
	//-------------------------------------------------------------------------------------

	/* 顯示輸入密碼的字 單純顯示 */
	void showPasswd()
	{
		HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD position;    // position 是一個 COORD 結構
		position.X = 5; //設定列在螢幕中心附近
		position.Y = 21; //設定行在螢幕中心附近
		SetConsoleCursorPosition(screen, position); //設置
		cout << "請輸入密碼：";
	}

	//-------------------------------------------------------------------------------------
	/*                             當註冊帳號時跳出來字									 */
	//-------------------------------------------------------------------------------------

	/* 顯示需要設置的帳號 單純顯示 */
	void showSetRegister()
	{
		HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD position;    // position 是一個 COORD 結構
		position.X = 5; //設定列在螢幕中心附近
		position.Y = 20; //設定行在螢幕中心附近
		SetConsoleCursorPosition(screen, position); //設置
		cout << "請輸入你要設置的帳號：";
	}

	//-------------------------------------------------------------------------------------
	/*                             當註冊帳號時跳出來字									 */
	//-------------------------------------------------------------------------------------

		/* 顯示需要設置的密碼 單純顯示 */
	void showSetPasswd()
	{
		HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD position;    // position 是一個 COORD 結構
		position.X = 5; //設定列在螢幕中心附近
		position.Y = 21; //設定行在螢幕中心附近
		SetConsoleCursorPosition(screen, position); //設置
		cout << "請輸入你要設置的密碼：";
	}
	//-------------------------------------------------------------------------------------
	/*                            當註冊帳號已經有人註冊時跳出來字						 */
	//-------------------------------------------------------------------------------------

	/* 顯示設置帳號失敗了 單純顯示 */
	void showFailSetAccount()
	{
		HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD position;    // position 是一個 COORD 結構
		position.X = 5; //設定列在螢幕中心附近
		position.Y = 22; //設定行在螢幕中心附近
		SetConsoleCursorPosition(screen, position); //設置
		cout << "此帳號已有人註冊，請更改帳號重新在註冊。按下Enter回到首頁重新註冊";
	}
	//-------------------------------------------------------------------------------------
	/*                            當密碼錯誤時跳出來字									 */
	//-------------------------------------------------------------------------------------

	/* 顯示設置帳號失敗了 單純顯示 */
	void showPasswdError()
	{
		HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD position;    // position 是一個 COORD 結構
		position.X = 5; //設定列在螢幕中心附近
		position.Y = 22; //設定行在螢幕中心附近
		SetConsoleCursorPosition(screen, position); //設置
		cout << "登入失敗，密碼錯誤。按下Enter重新登入";
	}

	//-------------------------------------------------------------------------------------
	/*                             當輸入帳號錯誤時跳出來								 */
	//-------------------------------------------------------------------------------------

		/* 顯示設置帳號失敗了 單純顯示 */
	void showAccountError()
	{
		HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD position;    // position 是一個 COORD 結構
		position.X = 5; //設定列在螢幕中心附近
		position.Y = 22; //設定行在螢幕中心附近
		SetConsoleCursorPosition(screen, position); //設置
		cout << "登入失敗，請回到首頁重新註冊。按下Enter重新登入";
	}

	//-------------------------------------------------------------------------------------
	/*                             讀取按鍵     										 */
	//-------------------------------------------------------------------------------------
	//鍵盤偵測
	char readKey()
	{
		char c = _getch();
		return c;
	}



	//-------------------------------------------------------------------------------------
	/*                              Board顯示(Admin權限)				                 */
	//-------------------------------------------------------------------------------------
	//先將boards vector清空 重新讀取 在顯示
	void showAdminSelectBoard(vector <Board>& boards)
	{
		/* 清空vector 因為需要重新讀取(為了有新增或刪除) */
		boards.clear(); //清空vector

		/* 設檔名 Board的檔案名為 Board.txt */
		string fileName = "Log/BoardLog/Board.txt";

		/* 設置 file stream */
		fstream UserLog;

		/* 開啟檔案 */
		UserLog.open(fileName);

		/* 判斷是否可以開啟檔案 */
		if (UserLog.is_open()) // 開啟成功就讀檔案
		{
			string ID, title;
			while (UserLog >> ID >> title) // 讀到檔案是空
			{
				boards.push_back(Board(ID, title));
			}
		}

		/* 關閉檔案 */
		UserLog.close();


		/* 顯示 */
		//第1行
		setCursorPosition(1, 0);
		setColor(DARKBLUE);
		cout << " 【主功能表】               　　　　　　　　　　　NTUST 看板"; //weight  118
		for (int i = 0; i < 119 - 78; i++)cout << " ";
		cout << "《" << "Administrator" << "》 ";
		setColor();
		//第2行
		setCursorPosition(1, 1);
		cout << " [Ｑ]返回  [Ｎ]新增  [Ｄ]刪除";
		for (int i = 0; i < 119 - 22; i++)cout << " ";
		setColor();
		//

		setCursorPosition(3, 2);
		/* 判斷vector 是不是空 防止bug */

		cursorPosition = { 45,14 }; // 設定在console光標的位置

		/* 判斷vector 是不是空 防止bug */
		if (!boards.empty())
		{
			for (int i = 0; i < boards.size(); i++)
			{
				setCursorAbsolutePosition(0, 1); // 換行的意思 
				cout << boards[i].ID << " " << boards[i].title; // 輸出Board看版
			};
		}
		else
		{
			setCursorAbsolutePosition(1, 1);
			cout << "目前沒有版面";
		}

		setCursorPosition(43, 15); // 設置光標在選擇的地方

	}

	//-------------------------------------------------------------------------------------
	/*                              Board顯示(Member&Guest權限)			                 */
	//-------------------------------------------------------------------------------------
	void showMemberSelectBoard(vector <Board>& boards)
	{

		/* 清空vector 防止重複讀取 */
		boards.clear(); //清空vector

		/* 設檔名 Board的檔案名為 Board.txt */
		string fileName = "Log/BoardLog/Board.txt";

		/* 設置 file stream */
		fstream UserLog;

		/* 開啟檔案 */
		UserLog.open(fileName);

		/* 判斷是否可以開啟檔案 */
		if (UserLog.is_open()) // 開啟成功就讀檔案
		{
			string ID, title;
			while (UserLog >> ID >> title) // 讀到檔案是空
			{
				boards.push_back(Board(ID, title));
			}
		}

		/* 關閉檔案 */
		UserLog.close();


		/* 顯示 */
		//第1行
		setCursorPosition(1, 0);
		setColor(DARKBLUE);
		cout << " 【主功能表】               　　　　　　　　　　　NTUST 看板"; //weight  118
		for (int i = 0; i < 119 - 78; i++)cout << " ";
		cout << "《" << "Administrator" << "》 ";
		setColor();
		//第2行
		setCursorPosition(1, 1);
		cout << " [Ｑ]返回";
		for (int i = 0; i < 119 - 10; i++)cout << " ";
		setColor();
		//

		cursorPosition = { 45,14 }; // 設定在console光標的位置

		/* 判斷vector 是不是空 防止bug */
		if (!boards.empty())
		{
			for (int i = 0; i < boards.size(); i++)
			{
				setCursorAbsolutePosition(0, 1); // 換行的意思 
				cout << boards[i].ID << " " << boards[i].title; // 輸出Board看版
			};
		}
		else
		{
			setCursorAbsolutePosition(1, 1);
			cout << "目前沒有版面";
		}

		setCursorPosition(43, 15); // 設置光標在選擇的地方
	}

	//-------------------------------------------------------------------------------------
	/*                              Board顯示要新增的看板ID(Admin權限)					 */
	//-------------------------------------------------------------------------------------
	string showNewBoardIDInput()
	{

		setCursorPosition(10, 15); // 設置光標位置
		cout << "輸入你要新增的版面ID: ";
		string input;
		cin >> input;

		return input;
	}

	//-------------------------------------------------------------------------------------
	/*                              Board顯示要新增的看板(Admin權限)				     */
	//-------------------------------------------------------------------------------------
	string showNewBoardInput()
	{

		setCursorPosition(10, 16); //  設置光標位置
		cout << "輸入你要新增的版面名稱: ";
		string input;
		cin >> input;

		return input;
	}

	//-------------------------------------------------------------------------------------
	/*                              Board顯示要刪除的看板(Admin權限)	     		     */
	//-------------------------------------------------------------------------------------
	string showDeleteBoardInput()
	{

		setCursorPosition(10, 15); //  設置光標位置
		cout << "輸入你要刪除的看板ID: ";
		string input;
		cin >> input;

		return input;
	}

	//-------------------------------------------------------------------------------------
	/*                              Board刪除看板(Admin權限)            			     */
	//-------------------------------------------------------------------------------------
	void DeleteBoard(vector <Board> boards, string deleteID)
	{

		/* 因為要重新讀取 */
		boards.clear(); //清空vector

		/* 設檔名 Board的檔案名為 Board.txt */
		string fileName = "Log/BoardLog/Board.txt";

		/* 設置 file stream */
		fstream UserLog;

		/* 開啟檔案 */
		UserLog.open(fileName, std::fstream::in); //寫入模式

		/* 先讀資料出來 */
		/* 判斷是否可以開啟檔案 */
		vector<string> ID, title;
		if (UserLog.is_open()) //開啟成功就讀檔案
		{

			string tmpID, tmpTitle;
			while (UserLog >> tmpID >> tmpTitle) //讀到檔案是空
			{
				ID.push_back(tmpID);
				title.push_back(tmpTitle);
			}
		}
		/* 關閉檔案  因為後面開啟模式要重設 */
		UserLog.close();

		/* 尋找代號 */
		int result = 99;
		for (int i = 0; i < ID.size(); i++)
		{
			if (ID[i] == deleteID)
			{
				result = i;
				break;
			}
		}
		/* 判斷是否有找到 有則刪除 */
		if (result != 99)
		{
			/* 刪除 ID */
			ID.erase(ID.begin() + result);
			/* 刪除 title */
			title.erase(title.begin() + result);

			/* 變更寫入模式 */
			UserLog.open(fileName, std::fstream::out); //寫入模式 

			/* 判斷是否可以開啟 */
			if (UserLog.is_open()) //開啟成功就讀檔案
			{
				/* 寫入版名 */
				for (int i = 0; i < ID.size(); i++)
				{
					UserLog << ID[i] << ' ' << title[i] << '\n';
				};
			}

		}

		/* 關閉檔案 */
		UserLog.close();

	}

	//-------------------------------------------------------------------------------------
	/*                              Board刪除看板(Admin權限)            			     */
	//-------------------------------------------------------------------------------------
	void CountBoardVisitor(Board &boards)
	{
		/* 設檔名 Board的檔案名為 Board.txt */
		string fileName = "Log/BoardLog/" +boards.title + "BoardViewer.txt";

		/* 設置 file stream */
		fstream UserLog;

		/* 開啟檔案 */
		UserLog.open(fileName, std::fstream::in); //讀取模式

		/* 先讀資料出來 */
		/* 判斷是否可以開啟檔案 */
		int viewerNum = 0;
		if (UserLog.is_open()) //開啟成功就讀檔案
		{
			UserLog >> viewerNum;
		}

		/* 關閉檔案 */
		UserLog.close();

		/* 設檔名 Board的檔案名為 Board.txt */
		fileName = "Log/BoardLog/" + boards.title + "BoardViewer.txt";

		viewerNum++;

		/* 開啟檔案 */
		UserLog.open(fileName, std::fstream::out); //讀取模式

		/* 先讀資料出來 */
		/* 判斷是否可以開啟檔案 */

		if (UserLog.is_open()) //開啟成功就讀檔案
		{
			UserLog << viewerNum;
		}

		/* 關閉檔案 */
		UserLog.close();
	}




	//-------------------------------------------------------------------------------------
	/*                             信箱列表顯示(Admin權限)								 */
	//-------------------------------------------------------------------------------------
	void showMailPost(Board& boards, User* users, string account)
	{

		/* 清空vector 因為需要重新讀取(為了有新增或刪除) */
		users->mail.clear();
		users->sender.clear();

		/* 設檔名 Mail 的檔案名為 receiver.txt */
		string fileName = "Log/AccountLog/" + account + "Mail.txt";

		/* 設置 file stream */
		ifstream myfile;

		/* 開啟檔案 */
		myfile.open(fileName);

		/* 判斷是否可以開啟檔案 */
		string tmpName, tmpMessage;
		while (getline(myfile, tmpName))
		{
			users->sender.push_back(tmpName);
			getline(myfile, tmpMessage);
			users->mail.push_back(tmpMessage);
		}


		/* 關閉檔案  因為後面開啟模式要重設 */
		myfile.close();

		/* 顯示 */
		setColor(31);
		setCursorPosition(1, 0);
		cout << "  編號                                     信箱";
		for (int i = 0; i < 118 - 48 - 5 - 3 - boards.title.size() - 3; i++)cout << " ";
		cout << "看板" << "《" << boards.title << "》"; // 最上端的顯示
		setColor();
		setCursorPosition(1, 1);
		cout << " [Ｑ]返回 [Ｍ]寄信 [Ｄ]刪除";
		setCursorPosition(1, 2);

		setColor(112);
		cout << "   編號  使用者     內容";
		for (int i = 0; i < 119 - 39; i++)cout << " ";
		setColor();

		setCursorPosition(3, 2);
		/* 判斷vector 是不是空 防止bug */

		if (!users->mail.empty())
		{
			for (int i = 0; i < users->mail.size(); i++)
			{
				setCursorAbsolutePosition(0, 1);
				cout << "   " << i << "   " << users->sender[i] << "    " << users->mail[i];
			};
		}
		else
		{
			setCursorAbsolutePosition(1, 1);
			cout << "目前沒有信件";
		}

		//setCursorPosition(0, 28); // 預計輸出在底部

		setCursorPosition(2, 3); // 設置光標在選擇的地方

	}

	//-------------------------------------------------------------------------------------
	/*                             檢查帳號是否存在(Admin權限)							 */
	//-------------------------------------------------------------------------------------
	//回傳0 可以寄
	//回傳1 帳號相同
	//回傳2 不存在此帳號
	int MailCheckReceiver(string receiver, User* users)
	{

		/* 設檔名 BoardPost的檔案名為 TitleBoard.txt */
		string fileName = "Log/AccountLog/" + receiver + ".txt";

		/* 設置 file stream */
		fstream UserLog;

		/* 開啟檔案 */
		UserLog.open(fileName, std::fstream::in); //讀取模式

		/* 判斷是否可以開啟檔案 */
		if (UserLog.is_open()) //開啟成功就讀檔案
		{
			if (users->account != receiver)
			{
				return 0;
			}
			UserLog.close();
			return 1;
		}
		else
		{
			UserLog.close();
			return 2;
		}
		/* 關閉檔案  因為後面開啟模式要重設 */
		UserLog.close();

	}

	//-------------------------------------------------------------------------------------
	/*                             寄信(Admin權限)										 */
	//-------------------------------------------------------------------------------------
	void MailSendMessage(User* users, string receiver, string message)
	{
		//先讀 在寫

		/* 先清空 */
		users->mail.clear();
		users->sender.clear();

		/* 設檔名 Mail 的檔案名為 receiver.txt */
		string fileName = "Log/AccountLog/" + receiver + "Mail.txt";

		/* 設置 file stream */
		ifstream myfile;

		/* 開啟檔案 */
		myfile.open(fileName);

		/* 判斷是否可以開啟檔案 */
		string tmpName, tmpMessage;
		while (getline(myfile, tmpName))
		{
			users->sender.push_back(tmpName);
			getline(myfile, tmpMessage);
			users->mail.push_back(tmpMessage);
		}


		/* 關閉檔案  因為後面開啟模式要重設 */
		myfile.close();

		/* 新增訊息 */
		users->sender.push_back(users->account);
		users->mail.push_back(message);

		/* 設置 file stream */
		fstream UserLog;

		/* 開啟檔案 */
		UserLog.open(fileName, std::fstream::out); //讀取模式

		/* 判斷是否可以開啟檔案 */
		if (UserLog.is_open()) //開啟成功就讀檔案
		{
			for (int i = 0; i < users->mail.size(); i++)
			{
				UserLog << users->account << '\n';
				UserLog << users->mail[i] << "\n";
			}
		}
		else
		{

		}
		/* 關閉檔案 */
		UserLog.close();

	}

	//-------------------------------------------------------------------------------------
	/*                             信箱刪除信件ID(Admin&Member權限)            			 */
	//-------------------------------------------------------------------------------------
	void DeleteMailID(User* users, string deleteID)
	{

		/* 因為要重新讀取 */
		users->mail.clear(); //清空vector

		/* 設檔名 BoardPost的檔案名為 TitleBoard.txt */
		string fileName = "Log/AccountLog/" + users->account + "Mail.txt";

		/* 設置 file stream */
		fstream UserLog;

		/* 開啟檔案 */
		UserLog.open(fileName, std::fstream::in); //讀取模式

		/* 先讀資料出來 */
		/* 判斷是否可以開啟檔案 */
		vector<string> mail;
		if (UserLog.is_open()) //開啟成功就讀檔案
		{
			string tmp;
			while (UserLog >> tmp) //讀到檔案是空
			{
				mail.push_back(tmp);
			}
		}
		/* 關閉檔案  因為後面開啟模式要重設 */
		UserLog.close();

		/* 尋找代號 */
		int result = 99999;

		/* 直接刪除 */
		if (!mail.empty()) {
			if ((stoi(deleteID) >= 0) && (stoi(deleteID) < mail.size()))
				/* 刪除 title */
				mail.erase(mail.begin() + stoi(deleteID));

			/* 變更寫入模式 */
			UserLog.open(fileName, std::fstream::out); //寫入模式 

			/* 判斷是否可以開啟 */
			if (UserLog.is_open()) //開啟成功就讀檔案
			{
				/* 寫入版名 */
				for (int i = 0; i < mail.size(); i++)
				{
					UserLog << mail[i] << '\n';
				};
			}

			/* 關閉檔案 */
			UserLog.close();
		}

	}

	//-------------------------------------------------------------------------------------
	/*                             信箱輸入帳號 顯示									 */
	//-------------------------------------------------------------------------------------
	string showMailNewNameInput()
	{

		setCursorPosition(10, 15); // 設置光標位置
		cout << "輸入你要寄信的使用者帳號: ";
		string input;
		cin >> input;

		return input;
	}

	//-------------------------------------------------------------------------------------
	/*                             信件內容顯示 要新增的  信件內容(Admin權限)			 */
	//-------------------------------------------------------------------------------------
	string showNewMailContentInput()
	{

		setCursorPosition(0, 0); // 設置光標位置
		cout << "輸入你要新增的信件內容: 按下 Ctrl + S 後 按 Enter 進行存檔  \n";
		string input;
		char c;
		getchar(); //清除換行字元
		while ((c = getchar()) != 19) /* Ctrl + S 後 按 Enter 進行存檔 */
		{
			if (c == '\n')continue; //防止跑版
			if (input.size() > 94)return input;
			input += c;
		}

		return input;
	}

	//-------------------------------------------------------------------------------------
	/*                             信箱輸入要刪除的信件ID								 */
	//-------------------------------------------------------------------------------------
	string showDeleteMailID()
	{

		setCursorPosition(10, 15); //  設置光標位置
		cout << "輸入你要刪除的信件ID: ";
		string input;
		cin >> input;

		return input;
	}
	//-------------------------------------------------------------------------------------
	/*                             顯示訪客不能使用信箱									 */
	//-------------------------------------------------------------------------------------
	void showGuestForbidUseMail()
	{

		setCursorPosition(10, 15); //  設置光標位置
		cout << "訪客不能使用信箱，輸入 Enter 回到上頁。";
		string input;
		getchar(); //清除
		char c;
		while ((c = getchar()) != '\n') /*  Enter 回到上頁 */
		{
		}	
	}



	//-------------------------------------------------------------------------------------
	/*                             貼文列表顯示(Admin權限)								 */
	//-------------------------------------------------------------------------------------
	void showAdminPost(Board& boards)
	{

		/* 清空vector 因為需要重新讀取(為了有新增或刪除) */
		boards.postID.clear(); //清空vector

		/* 設檔名 Board的檔案名為 Board.txt */
		string fileName = "Log/BoardLog/" + boards.title + "Board.txt";

		/* 設置 file stream */
		fstream UserLog;

		/* 開啟檔案 */
		UserLog.open(fileName, std::fstream::in | std::fstream::out | std::fstream::app); //讀取模式 寫入模式 添加模式

		/* 判斷是否可以開啟檔案 */
		if (UserLog.is_open()) // 開啟成功就讀檔案
		{
			int id;
			while (UserLog >> id) // 讀到檔案是空
			{
				boards.postID.push_back(id);
			}
		}
		else
		{

		}

		/* 關閉檔案 */
		UserLog.close();


		/* 設檔名 Board的檔案名為 Board.txt */
		fileName = "Log/BoardLog/" + boards.title + "BoardViewer.txt";

		/* 開啟檔案 */
		UserLog.open(fileName, std::fstream::in); //讀取模式

		/* 先讀資料出來 */
		/* 判斷是否可以開啟檔案 */
		string viewerNum;
		if (UserLog.is_open()) //開啟成功就讀檔案
		{
			UserLog >> viewerNum;
		}

		/* 關閉檔案 */
		UserLog.close();


		/* 顯示 */
		//第1行
		setCursorPosition(1, 0);
		setColor(DARKBLUE);
		cout << " 【主功能表】               　　　　　　　　　　　NTUST 看板"; //weight  118
		for (int i = 0; i < 119 - 76; i++)cout << " ";
		cout << "《" << boards.title << "》 ";
		setColor();
		//第2行
		setCursorPosition(1, 1);
		cout << " [Ｑ]返回  [Ｎ]新增  [Ｄ]刪除";
		for (int i = 0; i < 119 - 22; i++)cout << " ";
		setColor(112);
		//第3行
		setCursorPosition(1, 2);
		cout << "   編號      日 期  作 者       文章標題";
		for (int i = 0; i < 119 - 41 - viewerNum.size() - 1 - 7 ; i++)cout << " ";
		cout << "人氣：" << viewerNum << " ";
		setColor();
		//

		setCursorPosition(3, 2);
		/* 判斷vector 是不是空 防止bug */

		if (!boards.postID.empty())
		{
			for (int i = 0; i < boards.postID.size(); i++)
			{

				string fileName = "Log/PostsIDLog/" + to_string(boards.postID[i]) + ".txt";

				/* 設置 file stream */
				fstream UserLog;

				/* 開啟檔案 */
				UserLog.open(fileName, std::fstream::in | std::fstream::out | std::fstream::app); //讀取模式 寫入模式 添加模式

				//讀標題 作者 日期 讚跟虛聲

				/* 判斷是否可以開啟檔案 */
				if (UserLog.is_open()) // 開啟成功就讀檔案 
				{
					int good, bad;
					string date, auth, title, clean;
					setCursorAbsolutePosition(0, 1);
					UserLog >> good >> bad;
					UserLog >> clean >> date >> clean >> clean;
					UserLog >> auth;
					UserLog.close();
					ifstream myfile;
					myfile.open("Log/PostsIDLog/" + to_string(boards.postID[i]) + ".txt");
					getline(myfile, clean);
					getline(myfile, clean);
					getline(myfile, clean);
					getline(myfile, auth);
					getline(myfile, title);
					myfile.close();

					cout << "   " << boards.postID[i] << "  ";
					cout << intToStrPostViewer(good - bad) << "  ";
					setColor();
					cout << date << "  ";
					cout << auth << "       ";
					cout << title << '\n';

				}
				else
				{

				}


			};
		}
		else
		{
			setCursorAbsolutePosition(1, 1);
			cout << "目前沒有貼文";
		}

		setCursorPosition(2, 3); // 設置光標在選擇的地方

	}

	//-------------------------------------------------------------------------------------
	/*                             貼文列表顯示(Member									 */
	//-------------------------------------------------------------------------------------
	void showMemberPost(Board& boards)
	{
		/* 清空vector 因為需要重新讀取(為了有新增或刪除) */
		boards.postID.clear(); //清空vector

		/* 設檔名 Board的檔案名為 Board.txt */
		string fileName = "Log/BoardLog/" + boards.title + "Board.txt";

		/* 設置 file stream */
		fstream UserLog;

		/* 開啟檔案 */
		UserLog.open(fileName, std::fstream::in | std::fstream::out | std::fstream::app); //讀取模式 寫入模式 添加模式

		/* 判斷是否可以開啟檔案 */
		if (UserLog.is_open()) // 開啟成功就讀檔案
		{
			int id;
			while (UserLog >> id) // 讀到檔案是空
			{
				boards.postID.push_back(id);
			}
		}
		else
		{

		}

		/* 關閉檔案 */
		UserLog.close();

		/* 設檔名 Board的檔案名為 Board.txt */
		fileName = "Log/BoardLog/" + boards.title + "BoardViewer.txt";

		/* 開啟檔案 */
		UserLog.open(fileName, std::fstream::in); //讀取模式

		/* 先讀資料出來 */
		/* 判斷是否可以開啟檔案 */
		string viewerNum;
		if (UserLog.is_open()) //開啟成功就讀檔案
		{
			UserLog >> viewerNum;
		}

		/* 關閉檔案 */
		UserLog.close();

		/* 顯示 */
		//第1行
		setCursorPosition(1, 0);
		setColor(DARKBLUE);
		cout << " 【主功能表】               　　　　　　　　　　　NTUST 看板"; //weight  118
		for (int i = 0; i < 119 - 76; i++)cout << " ";
		cout << "《" << boards.title << "》 ";
		setColor();
		//第2行
		setCursorPosition(1, 1);
		cout << " [Ｑ]返回  [Ｎ]新增  [Ｄ]刪除";
		for (int i = 0; i < 119 - 22; i++)cout << " ";
		setColor(112);
		//第3行
		setCursorPosition(1, 2);
		cout << "   編號      日 期  作 者       文章標題";
		for (int i = 0; i < 119 - 41 - viewerNum.size() - 1 - 7; i++)cout << " ";
		cout << "人氣：" << viewerNum << " ";
		setColor();
		//

		setCursorPosition(3, 2);
		/* 判斷vector 是不是空 防止bug */

		if (!boards.postID.empty())
		{
			for (int i = 0; i < boards.postID.size(); i++)
			{

				string fileName = "Log/PostsIDLog/" + to_string(boards.postID[i]) + ".txt";

				/* 設置 file stream */
				fstream UserLog;

				/* 開啟檔案 */
				UserLog.open(fileName, std::fstream::in | std::fstream::out | std::fstream::app); //讀取模式 寫入模式 添加模式

				//讀標題 作者 日期 讚跟虛聲

				/* 判斷是否可以開啟檔案 */
				if (UserLog.is_open()) // 開啟成功就讀檔案 
				{
					int good, bad;
					string date, auth, title, clean;
					setCursorAbsolutePosition(0, 1);
					UserLog >> good >> bad;
					UserLog >> clean >> date >> clean >> clean;
					UserLog >> auth;
					UserLog.close();

					ifstream myfile;
					myfile.open("Log/PostsIDLog/" + to_string(boards.postID[i]) + ".txt");
					getline(myfile, clean);
					getline(myfile, clean);
					getline(myfile, clean);
					getline(myfile, auth);
					getline(myfile, title);
					myfile.close();

					cout << "   " << boards.postID[i] << "  ";
					cout << intToStrPostViewer(good - bad) << "  ";
					setColor();
					cout << date << "  ";
					cout << auth << "       ";
					cout << title << '\n';
				}
				else
				{

				}


			};
		}
		else
		{
			setCursorAbsolutePosition(1, 1);
			cout << "目前沒有貼文";
		}

		setCursorPosition(2, 3); // 設置光標在選擇的地方
	}

	//-------------------------------------------------------------------------------------
	/*                             貼文列表顯示(Guest權限)				         */
	//-------------------------------------------------------------------------------------
	void showGuestPost(Board& boards)
	{
		/* 清空vector 因為需要重新讀取(為了有新增或刪除) */
		boards.postID.clear(); //清空vector

		/* 設檔名 Board的檔案名為 Board.txt */
		string fileName = "Log/BoardLog/" + boards.title + "Board.txt";

		/* 設置 file stream */
		fstream UserLog;

		/* 開啟檔案 */
		UserLog.open(fileName, std::fstream::in | std::fstream::out | std::fstream::app); //讀取模式 寫入模式 添加模式

		/* 判斷是否可以開啟檔案 */
		if (UserLog.is_open()) // 開啟成功就讀檔案
		{
			int id;
			while (UserLog >> id) // 讀到檔案是空
			{
				boards.postID.push_back(id);
			}
		}
		else
		{

		}

		/* 關閉檔案 */
		UserLog.close();

		/* 設檔名 Board的檔案名為 Board.txt */
		fileName = "Log/BoardLog/" + boards.title + "BoardViewer.txt";

		/* 開啟檔案 */
		UserLog.open(fileName, std::fstream::in); //讀取模式

		/* 先讀資料出來 */
		/* 判斷是否可以開啟檔案 */
		string viewerNum;
		if (UserLog.is_open()) //開啟成功就讀檔案
		{
			UserLog >> viewerNum;
		}

		/* 關閉檔案 */
		UserLog.close();

		/* 顯示 */
		//第1行
		setCursorPosition(1, 0);
		setColor(DARKBLUE);
		cout << " 【主功能表】               　　　　　　　　　　　NTUST 看板"; //weight  118
		for (int i = 0; i < 119 - 76; i++)cout << " ";
		cout << "《" << boards.title << "》 ";
		setColor();
		//第2行
		setCursorPosition(1, 1);
		cout << " [Ｑ]返回";
		for (int i = 0; i < 119 - 10; i++)cout << " ";
		setColor(112);
		//第3行
		setCursorPosition(1, 2);
		cout << "   編號      日 期  作 者       文章標題";
		for (int i = 0; i < 119 - 41 - viewerNum.size() - 1 - 7; i++)cout << " ";
		cout << "人氣：" << viewerNum << " ";
		setColor();
		//

		setCursorPosition(3, 2);
		/* 判斷vector 是不是空 防止bug */

		if (!boards.postID.empty())
		{
			for (int i = 0; i < boards.postID.size(); i++)
			{
				string fileName = "Log/PostsIDLog/" + to_string(boards.postID[i]) + ".txt";

				/* 設置 file stream */
				fstream UserLog;

				/* 開啟檔案 */
				UserLog.open(fileName, std::fstream::in | std::fstream::out | std::fstream::app); //讀取模式 寫入模式 添加模式

				//讀標題 作者 日期 讚跟虛聲

				/* 判斷是否可以開啟檔案 */
				if (UserLog.is_open()) // 開啟成功就讀檔案 
				{
					int good, bad;
					string date, auth, title, clean;
					setCursorAbsolutePosition(0, 1);
					UserLog >> good >> bad;
					UserLog >> clean >> date >> clean >> clean;
					UserLog >> auth;
					UserLog.close();

					ifstream myfile;
					myfile.open("Log/PostsIDLog/" + to_string(boards.postID[i]) + ".txt");
					getline(myfile, clean);
					getline(myfile, clean);
					getline(myfile, clean);
					getline(myfile, auth);
					getline(myfile, title);
					myfile.close();

					cout << "   " << boards.postID[i] << "  ";
					cout << intToStrPostViewer(good - bad) << "  ";
					setColor();
					cout << date << "  ";
					cout << auth << "       ";
					cout << title << '\n';

				}
				else
				{

				}

				UserLog.close();
			};
		}
		else
		{
			setCursorAbsolutePosition(1, 1);
			cout << "目前沒有貼文";
		}

		setCursorPosition(2, 3); // 設置光標在選擇的地方

	}

	//-------------------------------------------------------------------------------------
	/*                             貼文列表顯示 要新增的貼文標題(Admin權限)				 */
	//-------------------------------------------------------------------------------------
	string showNewPostTitleInput()
	{

		setCursorPosition(10, 13); // 設置光標位置
		cout << "輸入你要新增的貼文標題。";
		setCursorPosition(10, 14); // 設置光標位置
		cout << "按下 Ctrl + S 後 按 Enter 進行存檔：";
		setCursorPosition(10, 15); // 設置光標位置
		string input;
		char c;
		getchar(); //清除換行字元
		while ((c = getchar()) != 19) /* 按下 Ctrl + S 後 按 Enter 進行存檔 */
		{
			if (c == '\n')continue;//防止跑版
			if (input.size() > 84)return input;
			input += c;
		}

		return input;
	}

	//-------------------------------------------------------------------------------------
	/*                             貼文列表顯示 要新增的貼文內容(Admin權限)				 */
	//-------------------------------------------------------------------------------------
	string showNewPostContentInput()
	{

		setCursorPosition(0, 0); // 設置光標位置
		cout << "輸入你要新增的內文: 按下 Ctrl + S 後 按 Enter 進行存檔  \n";
		string input;
		char c;
		getchar(); //清除換行字元
		while ((c = getchar()) != 19) /* Ctrl + S 後 按 Enter 進行存檔 */
		{
			input += c;
		}

		return input;
	}


	//-------------------------------------------------------------------------------------
	/*                             貼文列表顯示要刪除的看板ID(Admin權限)			 	 */
	//-------------------------------------------------------------------------------------
	string showDeletePost()
	{

		setCursorPosition(10, 15); //  設置光標位置
		cout << "輸入你要刪除的貼文ID: ";
		string input;
		cin >> input;

		return input;
	}

	//-------------------------------------------------------------------------------------
	/*                             貼文列表刪除看板PostID(Admin權限)            		 */
	//-------------------------------------------------------------------------------------
	void DeleteBoardPostID(Board& boards, string deleteID)
	{

		/* 先讀board postID */

		/* 因為要重新讀取 */
		boards.postID.clear(); //清空vector

		/* 設檔名 BoardPost的檔案名為 TitleBoard.txt */
		string fileName = "Log/BoardLog/" + boards.title + "Board.txt";

		/* 設置 file stream */
		fstream UserLog;

		/* 開啟檔案 */
		UserLog.open(fileName, std::fstream::in); //讀取模式

		/* 先讀資料出來 */
		/* 判斷是否可以開啟檔案 */
		vector<string> postID;
		if (UserLog.is_open()) //開啟成功就讀檔案
		{
			string tmpTitle;
			while (UserLog >> tmpTitle) //讀到檔案是空
			{
				postID.push_back(tmpTitle);
			}
		}
		/* 關閉檔案  因為後面開啟模式要重設 */
		UserLog.close();

		/* 尋找代號 */
		int result = 99999;
		for (int i = 0; i < postID.size(); i++)
		{
			if (postID[i] == deleteID)
			{
				result = i;
				break;
			}
		}
		/* 判斷是否有找到 有則刪除 */
		if (result != 99999)
		{
			/* 刪除 title */
			postID.erase(postID.begin() + result);

			/* 變更寫入模式 */
			UserLog.open(fileName, std::fstream::out); //寫入模式 

			/* 判斷是否可以開啟 */
			if (UserLog.is_open()) //開啟成功就讀檔案
			{
				/* 寫入版名 */
				for (int i = 0; i < postID.size(); i++)
				{
					UserLog << postID[i] << '\n';
				};
			}
		}

		/* 關閉檔案 */
		UserLog.close();

	}

	//-------------------------------------------------------------------------------------
	/*                             貼文列表刪除UserPostID(Admin權限)            		 */
	//-------------------------------------------------------------------------------------
	void DeleteUserPostID(User* user, string deleteID)
	{

		/* 先讀user postID */

		/* 因為要重新讀取 */
		user->postsID.clear(); //清空vector

		/* 設檔名 UserPost的檔案名為 帳號PostID.txt */
		string fileName = "Log/AccountLog/" + user->account + "PostID.txt";

		/* 設置 file stream */
		fstream UserLog;

		/* 開啟檔案 */
		UserLog.open(fileName, std::fstream::in); //讀取模式

		/* 先讀資料出來 */

		/* 判斷是否可以開啟檔案 */
		vector<string> postID;
		if (UserLog.is_open()) //開啟成功就讀檔案
		{
			string tmpPostID;
			while (UserLog >> tmpPostID) //讀到檔案是空
			{
				postID.push_back(tmpPostID);
			}
		}

		/* 關閉檔案 */
		UserLog.close();

		/* 尋找代號 */
		int result = 99999;
		for (int i = 0; i < postID.size(); i++)
		{
			if (postID[i] == deleteID)
			{
				result = i;
				break;
			}
		}
		/* 判斷是否有找到 有則刪除 */
		if (result != 99999)
		{
			/* 刪除 title */
			postID.erase(postID.begin() + result);

			/* 變更寫入模式 */
			UserLog.open(fileName, std::fstream::out); //寫入模式 

			/* 判斷是否可以開啟 */
			if (UserLog.is_open()) //開啟成功就讀檔案
			{
				/* 寫入版名 */
				for (int i = 0; i < postID.size(); i++)
				{
					UserLog << postID[i] << '\n';
				};
			}
		}

		/* 關閉檔案 */
		UserLog.close();

	}


	//-------------------------------------------------------------------------------------
	/*                             貼文列表刪除PostID(Admin權限)            			 */
	//-------------------------------------------------------------------------------------
	void DeletePostID(string deleteID)
	{
		/* 保留文件 不刪除 */
	}

	//-------------------------------------------------------------------------------------
	/*                             貼文列表刪除PostID(Member權限)            			 */
	//-------------------------------------------------------------------------------------
	//回傳 false 表示不是自己發表的文章
	//回傳 true  表示是自己的文章
	bool CheckDeleteUserPostID(User* user, string deleteID)
	{

		/* 先讀board postID */

		/* 因為要重新讀取 */
		user->postsID.clear(); //清空vector

		/* 設檔名 Board的檔案名為 Board.txt */
		string fileName = "Log/AccountLog/" + user->account + "PostID.txt";

		/* 設置 file stream */
		fstream UserLog;

		/* 開啟檔案 */
		UserLog.open(fileName, std::fstream::in); //寫入模式

		/* 先讀資料出來 */
		/* 判斷是否可以開啟檔案 */
		vector<string> postID;
		if (UserLog.is_open()) //開啟成功就讀檔案
		{
			string tmpPostID;
			while (UserLog >> tmpPostID) //讀到檔案是空
			{
				postID.push_back(tmpPostID);
			}
		}

		/* 關閉檔案 */
		UserLog.close();

		/* 尋找代號 */
		int result = 99999;
		for (int i = 0; i < postID.size(); i++)
		{
			if (postID[i] == deleteID)
			{
				result = i;
				break;
			}
		}
		/* 判斷是否有找到 有則刪除 */
		if (result != 99999)
		{
			UserLog.close();

			return true;
		}

		/* 關閉檔案 */
		UserLog.close();

		return false;

	}

	//-------------------------------------------------------------------------------------
	/*                             貼文列表刪除PostID(Member權限)            			 */
	//-------------------------------------------------------------------------------------
	/*
	0 人	不顯示					2000 ~ 4999 人	紅「爆!」
	1 ~ 10 人	白色數字			5000 ~ 9999 人	藍「爆!」
	11 ~ 50 人	黃色數字			10000 ~ 29999 人	青藍「爆!」
	51 ~ 99 人	紅色數字			30000 ~ 59999 人	綠「爆!」
	100 ~ 999 人	白色的「HOT」	60000 ~ 99999 人	黃「爆!」
	1000 ~ 1999 人	白「爆!」		100000+ 人	紫「爆!」
	*/	
	string intToStrPostViewer(int viewerNum)
	{
		if (viewerNum == 0) 
		{
			return "";
		}
		else if (viewerNum <= 10)
		{
			setColor();
			return to_string(viewerNum);
		}
		else if (viewerNum <= 50)
		{
			setColor(14);
			return to_string(viewerNum);
		}
		else if (viewerNum <= 99)
		{
			setColor(12);
			return to_string(viewerNum);
		}
		else if (viewerNum <= 999)
		{
			setColor();
			return "Hot";
		}
		else if (viewerNum <= 1999)
		{
			setColor();
			return "爆!";
		}
		else if (viewerNum <= 4999)
		{
			setColor(12);
			return "爆!";
		}
		else if (viewerNum <= 9999)
		{
			setColor(9);
			return "爆!";
		}
		else if (viewerNum <= 29999)
		{
			setColor(27);
			return "爆!";
		}
		else if (viewerNum <= 59999)
		{
			setColor(10);
			return "爆!";
		}
		else if (viewerNum <= 99999)
		{
		setColor(14);
		return "爆!";
		}
		else if (viewerNum >= 100000)
		{
			setColor(13);
			return "爆!";
		}
		else
		{
			return to_string(viewerNum);
		}

	}



	//-------------------------------------------------------------------------------------
	/*                             貼文內容顯示(Admin&Member權限)						 */
	//-------------------------------------------------------------------------------------
	void showPostContent(Board& boards, int currentPost)
	{
		ifstream myfile;
		myfile.open("Log/PostsIDLog/" + to_string(currentPost) + ".txt");

		string good, bad, date, auth, title;
		getline(myfile, good);
		getline(myfile, bad);
		getline(myfile, date);
		getline(myfile, auth);
		getline(myfile, title);

		myfile.close();
		//第1行
		setCursorPosition(1, 0);

		setColor(113);
		cout << "  作者  ";
		setColor(31);

		cout << " " << auth;

		for (int i = 0; i < 119 - 9 - 1 - auth.size(); i++)cout << " ";
		//第2行
		setCursorPosition(1, 1);

		setColor(113);
		cout << "  標題  ";
		setColor(31);
		cout << " " << title;
		for (int i = 0; i < 119 - 9 - 1 - title.size(); i++)cout << " ";
		//第3行
		setCursorPosition(1, 2);

		setColor(113);
		cout << "  時間  ";
		setColor(31);
		cout << " " << date;
		for (int i = 0; i < 119 - 9 - 1 - date.size(); i++)cout << " ";
		setColor();

		//第4行
		setCursorPosition(1, 3);
		setColor(112);
		cout << " [Ｙ]回應　[Ｘ]推文  [Ｇ]噓文  [Ｑ]返回";
		for (int i = 0; i < 119 - 40; i++)cout << " ";
		setColor();
		//
		setCursorPosition(1, 4);

		/* 輸出內文 */
		myfile.open("Log/PostsIDLog/" + to_string(currentPost) + "Content.txt");

		string line;

		while (getline(myfile, line))
		{
			setCursorAbsolutePosition(0, 1);
			cout << line << "\n";
		}

		setCursorAbsolutePosition(0, 1);

		for (int i = 0; i < 118; i++)cout << '-';

		setCursorAbsolutePosition(1, 1);

		myfile.close();

		/* 輸出評論 */
		myfile.open("Log/PostsIDLog/" + to_string(currentPost) + "Command.txt");

		while (getline(myfile, line))
		{
			cout << line;
			setCursorAbsolutePosition(0, 1);
		}

		myfile.close();

	}

	//-------------------------------------------------------------------------------------
	/*                             貼文內容顯示(Guest權限)								 */
	//-------------------------------------------------------------------------------------
	void showGuestPostContent(Board& boards, int currentPost)
	{
		ifstream myfile;
		myfile.open("Log/PostsIDLog/" + to_string(currentPost) + ".txt");

		string good, bad, date, auth, title;
		getline(myfile, good);
		getline(myfile, bad);
		getline(myfile, date);
		getline(myfile, auth);
		getline(myfile, title);

		myfile.close();
		//第1行
		setCursorPosition(1, 0);

		setColor(113);
		cout << "  作者  ";
		setColor(31);

		cout << " " << auth;

		for (int i = 0; i < 119 - 9 - 1 - auth.size(); i++)cout << " ";
		//第2行
		setCursorPosition(1, 1);

		setColor(113);
		cout << "  標題  ";
		setColor(31);
		cout << " " << title;
		for (int i = 0; i < 119 - 9 - 1 - title.size(); i++)cout << " ";
		//第3行
		setCursorPosition(1, 2);

		setColor(113);
		cout << "  時間  ";
		setColor(31);
		cout << " " << date;
		for (int i = 0; i < 119 - 9 - 1 - date.size(); i++)cout << " ";
		setColor();

		//第4行
		setCursorPosition(1, 3);
		setColor(112);
		cout << " [Ｑ]返回";
		for (int i = 0; i < 119 - 10; i++)cout << " ";
		setColor();
		//
		setCursorPosition(1, 4);

		/* 輸出內文 */
		myfile.open("Log/PostsIDLog/" + to_string(currentPost) + "Content.txt");

		string line;

		while (getline(myfile, line))
		{
			setCursorAbsolutePosition(0, 1);
			cout << line << "\n";
		}

		setCursorAbsolutePosition(0, 1);

		for (int i = 0; i < 118; i++)cout << '-';

		setCursorAbsolutePosition(1, 1);

		myfile.close();

		/* 輸出評論 */
		myfile.open("Log/PostsIDLog/" + to_string(currentPost) + "Command.txt");

		while (getline(myfile, line))
		{
			cout << line;
			setCursorAbsolutePosition(0, 1);
		}

		myfile.close();

	}

	//-------------------------------------------------------------------------------------
	/*                             貼文已推文過顯示(Admin與Member權限)					 */
	//-------------------------------------------------------------------------------------
	void showPressedPost()
	{

		HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
		COORD position;    // position 是一個 COORD 結構
		position.X = 30; //設定列在螢幕中心附近
		position.Y = 20; //設定行在螢幕中心附近
		SetConsoleCursorPosition(screen, position); //設置
		cout << "已推文過，不能重複操作。按下Enter回到文章";

	}

	//-------------------------------------------------------------------------------------
	/*                             貼文推文檢查(Admin與Member權限)						 */
	//-------------------------------------------------------------------------------------
	bool checkVotePost(Board& boards, int currentPost, string newAuth)
	{

		string fileName = "Log/PostsIDLog/" + to_string(currentPost) + "RecodePress.txt";

		/* 設置 file stream */
		fstream UserLog;

		/* 開啟檔案 */
		UserLog.open(fileName, std::fstream::in); //寫入模式

		vector<string> pressed;
		/* 判斷是否可以開啟檔案 */
		if (UserLog.is_open()) // 開啟成功就讀檔案 
		{
			string tmp;


			while (UserLog >> tmp)
			{
				pressed.push_back(tmp);
			}

		}
		else
		{

		}
		UserLog.close();

		/* 尋找代號 */
		int result = 99999;
		for (int i = 0; i < pressed.size(); i++)
		{
			if (pressed[i] == newAuth)
			{
				result = i;
				break;
			}
		}
		/* 判斷是否有找到 有則刪除 */
		if (result != 99999)
		{

			return false;
		}

		return true;
	}

	//-------------------------------------------------------------------------------------
	/*                             貼文推文(Admin與Member權限)							 */
	//-------------------------------------------------------------------------------------
	void upVotePost(Board& boards, int currentPost, string newAuth)
	{

		string recodePress = "";

		ifstream myfile;
		myfile.open("Log/PostsIDLog/" + to_string(currentPost) + "RecodePress.txt");

		string line;
		while (getline(myfile, line))
		{
			setCursorAbsolutePosition(0, 1);
			recodePress += line + "\n";
		}

		myfile.close();
		// 寫入進去

		// sys.wYear,sys.wMonth,sys.wDay,sys.wHour,sys.wMinute, sys.wSecond

		/* 設檔名 Board的檔案名為 PostID.txt */
		string fileName = "Log/PostsIDLog/" + to_string(currentPost) + "RecodePress.txt";

		/* 設置 file stream */
		fstream UserLog;

		/* 開啟檔案 */
		UserLog.open(fileName, std::fstream::out);// 寫入模式 

		UserLog << recodePress;


		UserLog << newAuth << "\n";

		/* 關閉檔案 */
		UserLog.close();

		fileName = "Log/PostsIDLog/" + to_string(currentPost) + ".txt";

		/* 開啟檔案 */
		UserLog.open(fileName, std::fstream::in | std::fstream::out | std::fstream::app); //讀取模式 寫入模式 添加模式

		//讀標題 作者 日期 讚跟虛聲		
		int good, bad;
		string date, auth, title;

		/* 判斷是否可以開啟檔案 */
		if (UserLog.is_open()) // 開啟成功就讀檔案 
		{
			UserLog >> good >> bad;
		}

		UserLog.close();

		myfile.open("Log/PostsIDLog/" + to_string(currentPost) + ".txt");

		string clean;
		getline(myfile, clean);
		getline(myfile, clean);
		getline(myfile, date);
		getline(myfile, auth);
		getline(myfile, title);

		myfile.close();

		good++;

		UserLog.close();

		UserLog.open(fileName, std::fstream::out); //寫入模式 

		/* 判斷是否可以開啟檔案 */
		if (UserLog.is_open()) // 開啟成功就讀檔案 
		{
			UserLog << good << '\n' << bad << '\n' << date << '\n' << auth << '\n' << title; // 讀到檔案是空		
		}


		UserLog.close();


	}

	//-------------------------------------------------------------------------------------
	/*                             貼文噓文(Admin與Member權限)							 */
	//-------------------------------------------------------------------------------------
	void downVotePost(Board& boards, int currentPost, string newAuth)
	{


		string recodePress = "";

		ifstream myfile;
		myfile.open("Log/PostsIDLog/" + to_string(currentPost) + "RecodePress.txt");

		string line;
		while (getline(myfile, line))
		{
			setCursorAbsolutePosition(0, 1);
			recodePress += line + "\n";
		}

		myfile.close();

		// 寫入進去

		// sys.wYear,sys.wMonth,sys.wDay,sys.wHour,sys.wMinute, sys.wSecond

		/* 設檔名 Board的檔案名為 PostID.txt */
		string fileName = "Log/PostsIDLog/" + to_string(currentPost) + "RecodePress.txt";

		/* 設置 file stream */
		fstream UserLog;

		/* 開啟檔案 */
		UserLog.open(fileName, std::fstream::out);// 寫入模式 

		UserLog << recodePress;


		UserLog << newAuth << "\n";

		/* 關閉檔案 */
		UserLog.close();

		fileName = "Log/PostsIDLog/" + to_string(currentPost) + ".txt";

		/* 開啟檔案 */
		UserLog.open(fileName, std::fstream::in | std::fstream::out | std::fstream::app); //讀取模式 寫入模式 添加模式

		//讀標題 作者 日期 讚跟虛聲		
		int good, bad;
		string date, auth, title;

		/* 判斷是否可以開啟檔案 */
		if (UserLog.is_open()) // 開啟成功就讀檔案 
		{
			UserLog >> good >> bad;
		}
		UserLog.close();

		myfile.open("Log/PostsIDLog/" + to_string(currentPost) + ".txt");

		string clean;
		getline(myfile, clean);
		getline(myfile, clean);
		getline(myfile, date);
		getline(myfile, auth);
		getline(myfile, title);

		myfile.close();

		bad++;

		UserLog.open(fileName, std::fstream::out); //寫入模式 

		/* 判斷是否可以開啟檔案 */
		if (UserLog.is_open()) // 開啟成功就讀檔案 
		{
			UserLog << good << '\n' << bad << '\n' << date << '\n' << auth << '\n' << title; // 讀到檔案是空
		}


		UserLog.close();

	}

	//-------------------------------------------------------------------------------------
	/*                             貼文回文(Admin與Member權限)							 */
	//-------------------------------------------------------------------------------------
	void commandPost(Board& boards, int currentPost, string newAuth, string newCommand)
	{
		string command = "";

		ifstream myfile;
		myfile.open("Log/PostsIDLog/" + to_string(currentPost) + "Command.txt");

		string line;
		while (getline(myfile, line))
		{
			setCursorAbsolutePosition(0, 1);
			command += line + "\n";
		}
		// 寫入進去
		myfile.close();

		/* 抓取時間 */
		SYSTEMTIME sys;
		GetLocalTime(&sys);

		// sys.wYear,sys.wMonth,sys.wDay,sys.wHour,sys.wMinute, sys.wSecond

		/* 設檔名 Board的檔案名為 PostID.txt */
		string fileName = "Log/PostsIDLog/" + to_string(currentPost) + "Command.txt";

		/* 設置 file stream */
		fstream UserLog;

		/* 開啟檔案 */
		UserLog.open(fileName, std::fstream::out);// 寫入模式 

		UserLog << command;
		UserLog << "→ " << newAuth << "：" << newCommand;
		string blank;
		for (int i = 0; i < 119 - newCommand.size() - newAuth.size() - 3 - 8 - 4 - 6; i++)
		{
			blank += ' ';
		}
		timeToStr(sys.wHour);
		timeToStr(sys.wMinute);
		UserLog << blank << timeToStr(sys.wMonth) << "/" << timeToStr(sys.wDay) << " ";
		UserLog << timeToStr(sys.wHour) << ":" << timeToStr(sys.wMinute) << "\n";
		/* 關閉檔案 */
		UserLog.close();

	}

	//-------------------------------------------------------------------------------------
	/*                             貼文回復 要回復的內容標題(Admin權限)				 */
	//-------------------------------------------------------------------------------------
	string showPostnewCommandInput()
	{

		setCursorPosition(10, 15); // 設置光標位置
		cout << "輸入你要回復的內容。按 Ctrl + S 後，按 Enter 進行回復：";
		string input;
		char c;
		getchar(); //清除換行字元
		while ((c = getchar()) != 19) /* Ctrl + S 後 按 Enter 進行存檔 */
		{
			if (c == '\n')continue; //防止跑版
			if (input.size() > 91)return input;
			input += c;
		}

		return input;
	}






	//-------------------------------------------------------------------------------------
	/*                              設置光標位置			                             */
	//-------------------------------------------------------------------------------------
	void setCursorPosition(short x, short y)
	{
		HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
		cursorPosition.X = x; // 更動儲存的光標位置
		cursorPosition.Y = y; // 更動儲存的光標位置
		SetConsoleCursorPosition(screen, cursorPosition); //設定光標
	}

	//-------------------------------------------------------------------------------------
	/*                              設置光標絕對位置			                         */
	//-------------------------------------------------------------------------------------
	void setCursorAbsolutePosition(short x, short y)
	{
		HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
		cursorPosition.X += x; // 從原本位置上進行增加
		cursorPosition.Y += y; // 從原本位置上進行增加
		SetConsoleCursorPosition(screen, cursorPosition); //設定光標
	}

	//-------------------------------------------------------------------------------------
	/*                              取得光標位置X										 */
	//-------------------------------------------------------------------------------------
	short getCursorPositionX()
	{
		return cursorPosition.X;
	}

	//-------------------------------------------------------------------------------------
	/*                              取得光標位置Y										 */
	//-------------------------------------------------------------------------------------
	short getCursorPositionY()
	{
		return cursorPosition.Y;
	}

	//-------------------------------------------------------------------------------------
	/*                              看板檢查光標是否可以向上							 */
	//-------------------------------------------------------------------------------------
	bool checkBoardCursorPositonUp(vector <Board> boards)
	{
		if (((cursorPosition.Y - 15) != 0))
		{
			return true;
		}
		return false;
	}

	//-------------------------------------------------------------------------------------
	/*                              看板檢查光標是否可以向下							*/
	//-------------------------------------------------------------------------------------
	bool checkBoardCursorPositonDown(vector <Board> boards)
	{
		if (((cursorPosition.Y - 15) != (boards.size() - 1)))
		{
			return true;
		}
		return false;
	}

	//-------------------------------------------------------------------------------------
	/*                              貼文列表檢查光標是否可以向上						 */
	//-------------------------------------------------------------------------------------
	bool checkPostCursorPositonUp(Board boards)
	{
		if (((cursorPosition.Y - 3) != 0))
		{
			return true;
		}
		return false;
	}

	//-------------------------------------------------------------------------------------
	/*                              貼文列表檢查光標是否可以向下						 */
	//-------------------------------------------------------------------------------------
	bool checkPostCursorPositonDown(Board boards)
	{
		if (((cursorPosition.Y - 3) != boards.postID.size() - 1))
		{
			return true;
		}
		return false;
	}

	//-------------------------------------------------------------------------------------
	/*                             文字顏色設置						                     */
	//-------------------------------------------------------------------------------------
	void setColor(int color = BLACK) {
		HANDLE hConsole;
		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, color);
	}

	//-------------------------------------------------------------------------------------
	/*                               清除畫面							                 */
	//------------------------------------------------------------------------------------- 
	//清除畫面 解決使用 system("cls") 會有閃爍問題 
	void clr()
	{
		system("cls");
		/*
		COORD cursorPosition;
		cursorPosition.X = 0;
		cursorPosition.Y = 0;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
		*/
	}

	//-------------------------------------------------------------------------------------
	/*                               螢幕最大化							                 */
	//-------------------------------------------------------------------------------------

		/*  Console設為全螢幕 */
	void consoleFullScreen()
	{
		//設置大小 x, y, width, height
		HWND hwnd = GetConsoleWindow();
		if (hwnd != NULL) { MoveWindow(hwnd, 0, 0, 1000, 500, TRUE); }
		//SetWindowPos(hwnd, 0, 0, 0, 1280, 720, SWP_SHOWWINDOW | SWP_NOMOVE);

		//最大化
		//HWND hwnd = GetForegroundWindow();
		//PostMessage(hwnd, WM_SYSCOMMAND, SC_MAXIMIZE, 0);

	}

	//-------------------------------------------------------------------------------------
	/*                               設置文字大小							             */
	//-------------------------------------------------------------------------------------

		/*  Console設置文字大小 */
	void consoleTextSize(int size)
	{
		CONSOLE_FONT_INFOEX cfi;
		cfi.cbSize = sizeof(cfi);
		cfi.nFont = 0;
		cfi.dwFontSize.X = 0;                   // Width of each character in the font
		cfi.dwFontSize.Y = size;                  // 修改文字大小
		cfi.FontFamily = FF_DONTCARE;
		cfi.FontWeight = FW_NORMAL;
		//std::wcscpy(cfi.FaceName, L"Console"); // Choose your font
		SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
	}

};

#endif // !VIEWER_H

