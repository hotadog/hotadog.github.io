/*测试用数据：
4人

张云天-15504938561-191478708-zhangyun@outlook.com
赵玉田-13081301692-138868618-zyt868618@outlook.com
祝英台-13154231586-202348443-zyt234844@outlook.com
卓依婷-15504935719-185451318-zyt451318@outlook.com

插入用：
张玉婷-78945612342-123456789-zyt456789@outlook.com
*/

#include<iostream>
#include<string>

using namespace std;

// 定义通讯录节点结构
struct Node {
    string data;       // 数据域
    Node* prev;     // 前驱指针
    Node* next;     // 后继指针
};

// 创建通讯录
Node* createList() {
    int n;
    string data;
    cout << "输入通讯录人数数: ";
    cin >> n;
    cout << endl;

    if (n <= 0) {
        cout << "无效的人数！" << endl;
        return nullptr;
    }

    Node* head = nullptr;
    Node* newNode, * temp;

    cout << "输入通讯录1的基本数据: ";
    cin >> data;
    head = new Node;
    head->data = data;
    head->prev = nullptr;
    head->next = nullptr;
    temp = head;

    for (int i = 2; i <= n; i++) {
        newNode = new Node;
        cout << "输入通讯录" << i << "的基本数据: ";
        cin >> data;
        newNode->data = data;
        newNode->prev = temp;
        newNode->next = nullptr;
        temp->next = newNode;
        temp = temp->next;
    }

    cout << "\n通讯录创建成功！" << endl;
    return head;
}

// 在指定位置插入节点
void insertNode(Node*& head) {
    if (head == nullptr) {
        cout << "通讯录为空！" << endl;
        return;
    }

    int pos;
    string data;
    cout << "输入要插入的位置: ";
    cin >> pos;
    cout << "输入要插入的数据: ";
    cin >> data;

    Node* newNode = new Node;
    newNode->data = data;

    if (pos == 1) {
        newNode->prev = nullptr;
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    else {
        Node* temp = head;
        for (int i = 1; i < pos - 1; i++) {
            temp = temp->next;
            if (temp == nullptr) {
                cout << "无效的插入位置！" << endl;
                delete newNode;
                return;
            }
        }

        newNode->prev = temp;
        newNode->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
    }

    cout << "\n节点插入成功！" << endl;
}

//查询指定位置的节点
void seekNode(Node*& head) {
    if (head == nullptr) {
        cout << "\n通讯录为空！" << endl;
        return;
    }

    int pos;
    cout << "输入要查询的位置: ";
    cin >> pos;

    Node* temp;
    if (pos == 1) {
        temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        cout << "查询为：" << temp->data;
    }
    else {
        temp = head;
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
            if (temp == nullptr) {
                cout << "查询失败！" << endl;
                return;
            }
        }

     //   temp->prev->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }
        cout << "查询为：" << temp->data;
    }

    cout << "\n查询成功！" << endl;
}

// 删除指定位置的节点
void deleteNode(Node*& head) {
    if (head == nullptr) {
        cout << "通讯录为空！" << endl;
        return;
    }

    int pos;
    cout << "输入要删除的位置: ";
    cin >> pos;

    Node* temp;
    if (pos == 1) {
        temp = head;
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        delete temp;
    }
    else {
        temp = head;
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
            if (temp == nullptr) {
                cout << "无效的删除位置！" << endl;
                return;
            }
        }

        temp->prev->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        }
        delete temp;
    }

    cout << "节点删除成功！" << endl;
}

// 遍历通讯录
void traverseList(Node* head) {
    if (head == nullptr) {
        cout << "通讯录为空！" << endl;
        return;
    }

    cout << "\n通讯录的成员: \n";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    // 创建通讯录
    head = createList();

    // 遍历通讯录
    traverseList(head);

    // 在指定位置插入节点
    insertNode(head);

    // 遍历通讯录
    traverseList(head);

    // 查找指定位置的节点
    seekNode(head);

    // 删除指定位置的节点
    deleteNode(head);

    // 遍历通讯录
    traverseList(head);

    return 0;
}
