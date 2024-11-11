#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

// ノードを初期化
void initialize_node(node* p, int val)
{
	p->pNext = NULL;
	p->data = val;
}

// リストを初期化
void initialize_list(list* l)
{
	l->header = NULL;
}

// 先頭にデータを追加
void push_front(list* l, node* p)
{
	if (l == NULL || p == NULL) return;

	// 新しいノードをリストの先頭に挿入
	p->pNext = l->header;
	l->header = p;
}

// pの次のノードを削除
void remove_next(list* l, node* p)
{
	if (l == NULL || p == NULL || p->pNext == NULL) return;

	// 削除するノード
	node* to_delete = p->pNext;

	// リンクを再接続
	p->pNext = to_delete->pNext;

	// メモリ解放
	free(to_delete);
}

// pの次のノードを取得
node* get_next(list* l, node* p)
{
	if (!p) return NULL;
	return p->pNext;
}
