#include "BoardManager/BoardManager.h"
#include <vector>
using namespace std;

int main()
{
	/*
	根據帳戶權限生成對應的使用者
	users.push_back(new Adiministrator(...))
	users.push_back(new Member(...))
	users.push_back(new Guest(...))
	*/

	BoardManager GM; /* 管理員 */
	GM.viewer.consoleFullScreen(); /* 最大化 */
	GM.viewer.consoleTextSize(24); /* 設定一開始的文字大小 */
	GM.viewer.clr(); /* 將原本控制台的資料清除 防止控制光標有Bug */
	GM.viewer.setColor(); //設置文字顏色
	while (1)
	{
		//GM.state = SELECT_BOARD; // 測試用

		switch (GM.state)
		{

		case MENU: // Enter the account

			/* 下面需要判斷是 登入還是註冊 如果輸入錯誤或登入成功才會跳脫迴圈 */
			while (1)
			{

				GM.viewer.showTitle(); /* 顯示 NUTST PTT */

				GM.viewer.showAccount_or_Register(); /* 輸出 請輸入new註冊或是guest訪客登入或是輸入帳號: 且移動光標*/

				string accountNumber_or_Register;
				cin >> accountNumber_or_Register; /* 判斷是要登入還是註冊還是登入還是訪客登入 */

				/* 判斷是要註冊還是輸入帳號還是訪客登入 */
				if (accountNumber_or_Register == "new") /* 註冊帳號 */
				{
					GM.viewer.clr(); /* 清除畫面 */

					/* 建立帳號 密碼 */
					GM.viewer.showSetRegister(); /* 輸出 請輸入你要設置的帳號: 且移動光標*/

					string account, passwd;

					/* 輸入帳號 */
					cin >> account;

					GM.viewer.showSetPasswd(); /* 輸出 請輸入你要設置的密碼: 且移動光標 */

					 /* 輸入密碼 */
					cin >> passwd;

					/* 進行註冊帳號的log寫入 回傳false 表示已註冊了 */
					if (!GM.create_Account(account, passwd))
					{
						GM.viewer.showFailSetAccount(); /* 輸出 帳號已有人註冊了 且移動光標 */

						while (!(_getch() == 13)); /* 按下enter 才可以跳離 */
					}
				}
				else if (accountNumber_or_Register == "guest") /* 訪客登入 */
				{
					/* +1 表示新的使用者 權限更新 */
					GM.current_user += 1;
					/* 給訪客的權限*/
					GM.users.push_back(new Guest());
					/* 進行到下一個模式 */
					GM.state = SELECT_BOARD; /* 進行到下一個模式 */
					GM.viewer.clr(); /* 清除畫面 */
					break;
				}
				else
				{
					/* 顯示輸入密碼 */
					GM.viewer.showPasswd(); /* 輸出 請輸入密碼: 且移動光標 */
					string passwd;
					cin >> passwd; /* 輸入密碼 */

					/* 判斷帳號與密碼是否正確 是的話則走下一步 */
					if (GM.login(accountNumber_or_Register, passwd) == 0)
					{
						/* 密碼正確時顯示 */

						/* +1 表示新的使用者 權限更新 */
						GM.current_user += 1;

						/* 判斷使用者權限 */
						if (GM.searchPermissionLevel(accountNumber_or_Register) == "0")
						{
							/* 給管理員的權限*/
							GM.users.push_back(new Admin());
						}
						else if (GM.searchPermissionLevel(accountNumber_or_Register) == "1")
						{
							/* 給一般使用者的權限*/
							GM.users.push_back(new Member());
						}
						else
						{
							/* 給訪客的權限*/
							GM.users.push_back(new Guest());
						}
						GM.users[GM.current_user]->account = accountNumber_or_Register; // 使用者名稱
						GM.state = SELECT_BOARD; /* 進行到下一個模式 */
						GM.viewer.clr(); /* 清除畫面 */
						break;
					}
					else if (GM.login(accountNumber_or_Register, passwd) == 1)
					{
						/* 密碼錯誤時的顯示 */
						GM.viewer.showPasswdError(); 
						while (!(_getch() == 13)); /* 按下enter 才可以跳離 */
					}
					else if (GM.login(accountNumber_or_Register, passwd) == 2)
					{
						/* 帳號錯誤時的顯示 */
						GM.viewer.showAccountError();
						while (!(_getch() == 13)); /* 按下enter 才可以跳離 */
					}

				}
				GM.viewer.clr(); /* 清除畫面 */
			};

			break;

		case SELECT_BOARD: // Display & Select next operation
	
				/* 分類權限來顯示介面 */
				if (GM.users[GM.current_user]->Permission_level == 0) // 管理員權限
				{
					/* 顯示介面 且讀檔 */

					GM.viewer.showAdminSelectBoard(GM.boards);
					while (1)
					{
						/* 讀取按鍵 */
						char key = GM.viewer.readKey();
						/* 按鍵事件 */
						if (key == 72) //上
						{
							if (GM.viewer.checkBoardCursorPositonUp(GM.boards))
							{
								GM.viewer.setCursorAbsolutePosition(0, -1); // 光標向上移動
							}
						}
						else if (key == 80) //下
						{
							if (GM.viewer.checkBoardCursorPositonDown(GM.boards))
							{
								GM.viewer.setCursorAbsolutePosition(0, +1); // 光標向下移動
							}
						}
						else if ((key == 'n') || (key == 'N'))  // N 新增看板
						{
							/* 清除畫面 */
							GM.viewer.clr();

							/* 進入輸入畫面 */
							string newID= GM.viewer.showNewBoardIDInput(); // 回傳輸入的內容
							string newBoard = GM.viewer.showNewBoardInput(); // 回傳輸入的內容

							/* 進行初始化且寫入檔案 */
							GM.boards.push_back(Board(newID + ' ' +newBoard));
							/* 清除畫面 */
							GM.viewer.clr(); 
							/* 回到原本畫面 */
							GM.viewer.showAdminSelectBoard(GM.boards);
						}
						else if ((key == 'd') || (key == 'D'))  // D 刪除看板
						{ 
							GM.viewer.clr();

							string deleteBoard = GM.viewer.showDeleteBoardInput(); // 回傳輸入的內容

							GM.viewer.DeleteBoard(GM.boards,deleteBoard);

							/* 清除畫面 */
							GM.viewer.clr();
							/* 回到原本畫面 */
							GM.viewer.showAdminSelectBoard(GM.boards);

						}
						else if ((key == 'q') || (key == 'Q'))  //Q 離開
						{
							GM.state = MENU; /* 進行到上一個模式 */
							GM.viewer.clr(); /* 清除畫面 */
							break;
						}
						else if (key == 13)  //Enter 進入下個模式
						{
							
							GM.current_boards = GM.viewer.getCursorPositionY() - 15;
							GM.state = BOARD; /* 進行到下一個模式 */
							GM.viewer.clr(); /* 清除畫面 */

							/* 看板人氣增加在這裡做 */
							GM.viewer.CountBoardVisitor(GM.boards[GM.current_boards]);
							break;
						}
					};
					
					
				}
				else  // 會員與訪客權限
				{
					/* 顯示介面 */
					GM.viewer.showMemberSelectBoard(GM.boards);
					while (1)
					{
						/* 讀取按鍵 */
						char key = GM.viewer.readKey();
						/* 按鍵事件 */
						if (key == 72) //方向上
						{
							if (GM.viewer.checkBoardCursorPositonUp(GM.boards))
							{
								GM.viewer.setCursorAbsolutePosition(0, -1); // 光標向上移動
							}
						}
						else if (key == 80)  //方向下
						{
							if (GM.viewer.checkBoardCursorPositonDown(GM.boards))
							{
								GM.viewer.setCursorAbsolutePosition(0, +1); // 光標向下移動
							}
						}
						else if ((key == 'q') || (key == 'Q'))  //Q 離開
						{
							GM.state = MENU; /* 進行到上一個模式 */
							GM.viewer.clr(); /* 清除畫面 */
							break;
						}
						else if (key == 13)  //Enter  進入下個模式
						{
							GM.state = BOARD; /* 進行到下一個模式 */
							GM.current_boards = GM.viewer.getCursorPositionY() - 15;
							GM.viewer.clr(); /* 清除畫面 */

							/* 看板人氣增加在這裡做 */
							GM.viewer.CountBoardVisitor(GM.boards[GM.current_boards]);
							break;
						}
					};
				}
			

			break;

		case BOARD: // Display each post & select post

			/* 信箱的特別判斷 */
			if (GM.boards[GM.current_boards].title == "信箱")
			{	
				/* 額外判斷 訪客不能使用信箱 */
				if (GM.users[GM.current_user]->Permission_level == 2)
				{
					GM.viewer.clr();
					GM.viewer.showGuestForbidUseMail();
					GM.viewer.clr(); /* 清除畫面 */
					GM.state = SELECT_BOARD; /* 進行到上一個模式 */
					GM.viewer.clr(); /* 清除畫面 */
					break;
				}

				string auth = GM.users[GM.current_user]->account; // 使用者名稱

				GM.viewer.showMailPost(GM.boards[GM.current_boards],GM.users[GM.current_user], auth);

				while (1)
				{
					/* 讀取按鍵 */
					char key = GM.viewer.readKey();
					if ((key == 'm') || (key == 'M'))  //M 寄信
					{
						GM.viewer.clr(); /* 清除畫面 */

						string receiver = GM.viewer.showMailNewNameInput(); // 回傳輸入的內容

						if (GM.viewer.MailCheckReceiver(receiver, GM.users[GM.current_user]) == 0)
						{
							GM.viewer.clr(); /* 清除畫面 */

							string content = GM.viewer.showNewMailContentInput();

							GM.viewer.MailSendMessage(GM.users[GM.current_user], receiver, content);//寄信 寫檔

							GM.viewer.clr(); /* 清除畫面 */

							GM.viewer.showMailPost(GM.boards[GM.current_boards], GM.users[GM.current_user], auth);

						}

						else if (GM.viewer.MailCheckReceiver(receiver, GM.users[GM.current_user]) == 1)
						{
							GM.viewer.clr(); /* 清除畫面 */

							GM.viewer.setCursorPosition(30, 20);

							cout << "你不可以寄信給自己，按下enter 才可以跳離。" << endl;

							while (!(_getch() == 13)); /* 按下enter 才可以跳離 */

							GM.viewer.clr(); /* 清除畫面 */

							GM.viewer.showMailPost(GM.boards[GM.current_boards], GM.users[GM.current_user], auth);
						} //s

						else if (GM.viewer.MailCheckReceiver(receiver, GM.users[GM.current_user]) == 2)
						{
							GM.viewer.clr(); /* 清除畫面 */

							GM.viewer.setCursorPosition(30, 20);

							cout << "此使用者不存在，按下enter 才可以跳離。" << endl;

							while (!(_getch() == 13)); /* 按下enter 才可以跳離 */

							GM.viewer.clr(); /* 清除畫面 */

							GM.viewer.showMailPost(GM.boards[GM.current_boards], GM.users[GM.current_user], auth);
						} //s
					}
					else if ((key == 'd') || (key == 'D'))  //D 刪掉信
					{
						GM.viewer.clr(); /* 清除畫面 */

						string deleteID = GM.viewer.showDeleteMailID();

						GM.viewer.DeleteMailID(GM.users[GM.current_user], deleteID);

						GM.viewer.clr(); /* 清除畫面 */

						GM.viewer.showMailPost(GM.boards[GM.current_boards], GM.users[GM.current_user], auth);

					}
					else if ((key == 'q') || (key == 'Q'))  //Q 離開
					{
						GM.state = SELECT_BOARD; /* 進行到上一個模式 */
						GM.viewer.clr(); /* 清除畫面 */
						break;
					};
				}
			}
			/* 分類權限來顯示介面 */
			else if (GM.users[GM.current_user]->Permission_level == 0) // 管理員權限
			{
				/* 顯示介面 且讀檔 */

				GM.viewer.showAdminPost(GM.boards[GM.current_boards]);

				while (1)
				{
					/* 讀取按鍵 */
					char key = GM.viewer.readKey();
					/* 按鍵事件 */
					if (key == 72) //上
					{
						if (GM.viewer.checkPostCursorPositonUp(GM.boards[GM.current_boards]))
						{
							GM.viewer.setCursorAbsolutePosition(0, -1); // 光標向上移動
						}
					}
					else if (key == 80) //下
					{
						if (GM.viewer.checkPostCursorPositonDown(GM.boards[GM.current_boards]))
						{
							GM.viewer.setCursorAbsolutePosition(0, +1); // 光標向下移動
						}
					}
					else if ((key == 'n') || (key == 'N'))  // N 新增看板
					{
						/* 清除畫面 */
						GM.viewer.clr();

						// 資料格式
						// 1.讚 2.虛 3.日期 4.作者 5.標題 6.接下來都是內文

						string newTitle = GM.viewer.showNewPostTitleInput(); // 回傳輸入的內容

						/* 清除畫面 */
						GM.viewer.clr();

						string newContent = GM.viewer.showNewPostContentInput(); // 回傳輸入的內容

						string auth = GM.users[GM.current_user]->account; // 使用者名稱


						/* 抓取postID (每篇不一樣 所以要跟boardManager要) */
						int newPostID = GM.getPostID();

						/* 進行初始化且寫入檔案 */
						GM.boards[GM.current_boards].createPost(newPostID, newTitle, newContent, auth);

						/* 新增使用者建立過的文章紀錄 */
						GM.users[GM.current_user]->updatePostsID(newPostID);

						/* 清除畫面 */
						GM.viewer.clr();

						/* 回到原本畫面 */
						GM.viewer.showAdminPost(GM.boards[GM.current_boards]);
					}
					else if ((key == 'd') || (key == 'D'))  // D 刪除看板
					{
						/* 清除畫面 */
						GM.viewer.clr();

						string deletePostID = GM.viewer.showDeleteBoardInput(); // 回傳輸入的編號

						string auth = GM.users[GM.current_user]->account; // 使用者名稱

						//要清理board的編號 userPosts.txt postlog.txt
						GM.viewer.DeleteBoardPostID(GM.boards[GM.current_boards], deletePostID);

						GM.viewer.DeleteUserPostID(GM.users[GM.current_user], deletePostID);

						GM.viewer.DeletePostID(deletePostID); //不用管

						/* 清除畫面 */
						GM.viewer.clr();
						/* 回到原本畫面 */
						GM.viewer.showAdminPost(GM.boards[GM.current_boards]);

					}
					else if ((key == 'q') || (key == 'Q'))  //Q 離開
					{
						GM.state = SELECT_BOARD; /* 進行到上一個模式 */
						GM.viewer.clr(); /* 清除畫面 */
						break;
					}
					else if (key == 13)  //Enter 進入下個模式
					{
						GM.current_post = GM.boards[GM.current_boards].postID[GM.viewer.getCursorPositionY() - 3];
						GM.state = POST; /* 進行到下一個模式 */
						GM.viewer.clr(); /* 清除畫面 */
						break;
					}
				};

			}
			else if (GM.users[GM.current_user]->Permission_level == 1) // Member
			{
				/* 顯示介面 且讀檔 */
				GM.viewer.showMemberPost(GM.boards[GM.current_boards]);

				while (1)
				{
					/* 讀取按鍵 */
					char key = GM.viewer.readKey();

					/* 按鍵事件 */
					if (key == 72) //上
					{
						if (GM.viewer.checkPostCursorPositonUp(GM.boards[GM.current_boards]))
						{
							GM.viewer.setCursorAbsolutePosition(0, -1); // 光標向上移動
						}
					}
					else if (key == 80) //下
					{
						if (GM.viewer.checkPostCursorPositonDown(GM.boards[GM.current_boards]))
						{
							GM.viewer.setCursorAbsolutePosition(0, +1); // 光標向下移動
						}
					}
					else if ((key == 'n') || (key == 'N'))  // N 新增看板
					{
						/* 清除畫面 */
						GM.viewer.clr();

						// 資料格式
						// 1.讚 2.虛 3.日期 4.作者 5.標題 6.接下來都是內文

						string newTitle = GM.viewer.showNewPostTitleInput(); // 回傳輸入的內容

						GM.viewer.clr();

						string newContent = GM.viewer.showNewPostContentInput(); // 回傳輸入的內容

						string auth = GM.users[GM.current_user]->account; // 使用者名稱


						/* 抓取postID (每篇不一樣 所以要跟boardManager要) */
						int newPostID = GM.getPostID();

						/* 進行初始化且寫入檔案 */
						GM.boards[GM.current_boards].createPost(newPostID, newTitle, newContent, auth);
						/* 新增使用者建立過的文章紀錄 */
						GM.users[GM.current_user]->updatePostsID(newPostID);
						/* 清除畫面 */
						GM.viewer.clr();

						/* 回到原本畫面 */
						GM.viewer.showMemberPost(GM.boards[GM.current_boards]);
					}
					else if ((key == 'd') || (key == 'D'))  // D 刪除看板
					{
						GM.viewer.clr();
						string deletePostID = GM.viewer.showDeleteBoardInput(); // 回傳輸入的編號

						string auth = GM.users[GM.current_user]->account; // 使用者名稱

						//要清理board的編號 userPosts.txt postlog.txt
						if (GM.viewer.CheckDeleteUserPostID(GM.users[GM.current_user], deletePostID))
						{
							GM.viewer.DeleteBoardPostID(GM.boards[GM.current_boards], deletePostID);
							GM.viewer.DeleteUserPostID(GM.users[GM.current_user], deletePostID);
							GM.viewer.DeletePostID(deletePostID); //可以不用管這行
						}
						else
						{
							GM.viewer.clr();

							GM.viewer.setCursorPosition(30, 20);

							cout << "此文章的作者不是你，按下enter 才可以跳離。" << endl;

							while (!(_getch() == 13)); /* 按下enter 才可以跳離 */
						}

						/* 清除畫面 */
						GM.viewer.clr();

						/* 回到原本畫面 */
						GM.viewer.showMemberPost(GM.boards[GM.current_boards]);
					}
					else if ((key == 'q') || (key == 'Q'))  //Q 離開
					{
						GM.state = SELECT_BOARD; /* 進行到上一個模式 */
						GM.viewer.clr(); /* 清除畫面 */
						break;
					}
					else if (key == 13)  //Enter 進入下個模式
					{
						GM.current_post = GM.boards[GM.current_boards].postID[GM.viewer.getCursorPositionY() - 3];
						GM.state = POST; /* 進行到下一個模式 */
						GM.viewer.clr(); /* 清除畫面 */
						break;
					}
				};
			}
			else if (GM.users[GM.current_user]->Permission_level == 2) // Guest
			{
			/* 顯示介面 且讀檔 */
			GM.viewer.showGuestPost(GM.boards[GM.current_boards]);

			while (1)
			{
				/* 讀取按鍵 */
				char key = GM.viewer.readKey();
				/* 按鍵事件 */
				if (key == 72) //上
				{
					if (GM.viewer.checkPostCursorPositonUp(GM.boards[GM.current_boards]))
					{
						GM.viewer.setCursorAbsolutePosition(0, -1); // 光標向上移動
					}
				}
				else if (key == 80) //下
				{
					if (GM.viewer.checkPostCursorPositonDown(GM.boards[GM.current_boards]))
					{
						GM.viewer.setCursorAbsolutePosition(0, +1); // 光標向下移動
					}
				}
				else if ((key == 'q') || (key == 'Q'))  //Q 離開
				{
					GM.state = SELECT_BOARD; /* 進行到上一個模式 */
					GM.viewer.clr(); /* 清除畫面 */
					break;
				}
				else if (key == 13)  //Enter 進入下個模式
				{
					GM.current_post = GM.boards[GM.current_boards].postID[GM.viewer.getCursorPositionY() - 3];
					GM.state = POST; /* 進行到下一個模式 */
					GM.viewer.clr(); /* 清除畫面 */
					break;
				}
			};
			}


			break;
		case POST:

			/* 分類權限來顯示介面 */
			/* 還在撰寫中 */
			if (GM.boards[GM.current_boards].title == "信箱")
			{
			}
			else if (GM.users[GM.current_user]->Permission_level == 0) // 管理員權限
			{
				GM.viewer.showPostContent(GM.boards[GM.current_boards],GM.current_post);

				while (1)
				{
					char key = GM.viewer.readKey();

					if ((key == 'q') || (key == 'Q'))  //Q 離開
					{
						GM.state = BOARD; /* 進行到上一個模式 */
						GM.viewer.clr(); /* 清除畫面 */
						break;
					}
					else if ((key == 'x') || (key == 'X'))  //X 推文
					{

						string auth = GM.users[GM.current_user]->account; // 使用者名稱

						if (GM.viewer.checkVotePost(GM.boards[GM.current_boards], GM.current_post, auth))
						{
							GM.viewer.upVotePost(GM.boards[GM.current_boards], GM.current_post, auth);

						}
						else
						{
							GM.viewer.clr();

							GM.viewer.showPressedPost(); // 顯示已投票過

							while (!(_getch() == 13)); /* 按下enter 才可以跳離 */

							GM.viewer.clr();

							GM.viewer.showPostContent(GM.boards[GM.current_boards], GM.current_post); // 顯示
						}
					}
					else if ((key == 'g') || (key == 'G'))  //G 噓文
					{
						string auth = GM.users[GM.current_user]->account; // 使用者名稱
						if (GM.viewer.checkVotePost(GM.boards[GM.current_boards], GM.current_post, auth))
						{
							GM.viewer.downVotePost(GM.boards[GM.current_boards], GM.current_post, auth);
						}
						else
						{
							GM.viewer.clr();

							GM.viewer.showPressedPost(); // 顯示已投票過

							while (!(_getch() == 13)); /* 按下enter 才可以跳離 */

							GM.viewer.clr();

							GM.viewer.showPostContent(GM.boards[GM.current_boards], GM.current_post); // 顯示
						}
					}
					else if ((key == 'y') || (key == 'Y'))  //Y 回復
					{
						/* 清除畫面 */
						GM.viewer.clr();

						string newCommand = GM.viewer.showPostnewCommandInput(); // 回傳輸入的內容

						string auth = GM.users[GM.current_user]->account; // 使用者名稱

						GM.viewer.commandPost(GM.boards[GM.current_boards], GM.current_post, auth, newCommand);

						/* 清除畫面 */
						GM.viewer.clr();

						/* 回到原本畫面 */
						GM.viewer.showPostContent(GM.boards[GM.current_boards], GM.current_post);

					}
				}
			}
			else if (GM.users[GM.current_user]->Permission_level == 1) // 會員
			{

				GM.viewer.showPostContent(GM.boards[GM.current_boards], GM.current_post);

				while (1)
				{
					char key = GM.viewer.readKey();

					if ((key == 'q') || (key == 'Q'))  //Q 離開
					{
						GM.state = BOARD; /* 進行到上一個模式 */
						GM.viewer.clr(); /* 清除畫面 */
						break;
					}
					else if ((key == 'x') || (key == 'X'))  //X 推文
					{
						string auth = GM.users[GM.current_user]->account; // 使用者名稱
						if (GM.viewer.checkVotePost(GM.boards[GM.current_boards], GM.current_post, auth))
						{
							GM.viewer.upVotePost(GM.boards[GM.current_boards], GM.current_post, auth);
						}
						else
						{
							GM.viewer.clr();

							GM.viewer.showPressedPost(); // 顯示已投票過

							while (!(_getch() == 13)); /* 按下enter 才可以跳離 */

							GM.viewer.clr();

							GM.viewer.showPostContent(GM.boards[GM.current_boards], GM.current_post); // 顯示
						}
					}
					else if ((key == 'g') || (key == 'G'))  //G 噓文
					{
						string auth = GM.users[GM.current_user]->account; // 使用者名稱
						if (GM.viewer.checkVotePost(GM.boards[GM.current_boards], GM.current_post, auth))
						{
							GM.viewer.downVotePost(GM.boards[GM.current_boards], GM.current_post, auth);
						}
						else
						{
							GM.viewer.clr();

							GM.viewer.showPressedPost(); // 顯示已投票過

							while (!(_getch() == 13)); /* 按下enter 才可以跳離 */

							GM.viewer.clr();

							GM.viewer.showPostContent(GM.boards[GM.current_boards], GM.current_post); // 顯示
						}
					}
					else if ((key == 'y') || (key == 'Y'))  //Y 回復
					{
						/* 清除畫面 */
						GM.viewer.clr();

						string newCommand = GM.viewer.showPostnewCommandInput(); // 回傳輸入的內容

						string auth = GM.users[GM.current_user]->account; // 使用者名稱

						GM.viewer.commandPost(GM.boards[GM.current_boards], GM.current_post, auth, newCommand);

						/* 清除畫面 */
						GM.viewer.clr();

						/* 回到原本畫面 */
						GM.viewer.showPostContent(GM.boards[GM.current_boards], GM.current_post);

					}

				}
			}
			else if (GM.users[GM.current_user]->Permission_level == 2) // 訪客
			{

			GM.viewer.showGuestPostContent(GM.boards[GM.current_boards], GM.current_post);

				while (1)
				{
					char key = GM.viewer.readKey();

					if ((key == 'q') || (key == 'Q'))  //Q 離開
					{
						GM.state = BOARD; /* 進行到上一個模式 */
						GM.viewer.clr(); /* 清除畫面 */
						break;
					}
				}
			}

		break;
		}
	};
	
	

	return 0;
}