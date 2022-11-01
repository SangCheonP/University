#include <cstdlib>
#include <cassert>
#include <iostream>

using namespace std;

class dnode {
public:
	typedef double value_type; //double�� typedef�� value_type���� ������

	dnode(const value_type& init_data = value_type(), dnode* init_fore = NULL, dnode* init_back = NULL) //data�� double�� ��, fore, back�� NULL�� �ʱ�ȭ�ϴ� ������
	{
		data_field = init_data;
		link_fore = init_fore;
		link_back = init_back;
	}

	void set_data(const value_type& new_data) //data�� �޾� �ɹ����� data_field�� ����
	{
		data_field = new_data;
	}

	void set_fore(dnode* new_fore) //new_fore�� �޾� ���� dnode�� ����Ű�� link_fore�� ����
	{
		link_fore = new_fore;
	}

	void set_back(dnode* new_back) //new_back�� �޾� �� dnode�� ����Ű�� link_back�� ����
	{
		link_back = new_back;
	}

	value_type data() const //data_field�� ����� ���� ��ȯ
	{
		return data_field;
	}

	const dnode* fore() const //link_fore�� ����� ���� ��ȯ(������ �� ����)
	{
		return link_fore;
	}

	dnode* fore() //link_fore�� ����� ���� ��ȯ(�� ���氡��)
	{
		return link_fore;
	}

	const dnode* back() const //link_back�� ����� ���� ��ȯ(������ �� ����)
	{
		return link_back;
	}

	dnode* back() //link_back�� ����� ���� ��ȯ(�� ���氡��)
	{
		return link_back;
	}

private:
	value_type data_field; //���� ������, ���� dnode, �� dnode�� ���� �ɹ��Լ��� ����
	dnode* link_fore;
	dnode* link_back;
};

dnode* head_ptr = NULL;
dnode* tail_ptr = NULL;

size_t list_length(const dnode* head_ptr) //���� dnode�� ���̸� ��ȯ�ϴ� �Լ�
{
	size_t answer = 0;
	const dnode* cursor;
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->fore()) {
		++answer;
	}
	return answer;
}

void list_head_insert(dnode*& head_ptr, const dnode::value_type& entry) //dnode�� ���� �տ� dnode�� �ϳ� �߰��ϴ� �Լ�
{
	dnode* insert_ptr = new dnode();
	insert_ptr->set_fore(head_ptr);
	insert_ptr->set_data(entry);
	insert_ptr->set_back(NULL);
	if (head_ptr != NULL) //���� �̹� dnode�� �ϳ��� �����Ͽ� �� �տ� dnode�� �߰��ؾ� �� ���� ���
	{
		head_ptr->set_back(insert_ptr);
	}
	head_ptr = insert_ptr;
}

void list_insert(dnode* previous_ptr, const dnode::value_type& entry) //dnode�� dnode���̿� ���ο� dnode�� �߰��ϴ� �Լ�
{
	dnode* insert_ptr;

	insert_ptr = new dnode;
	insert_ptr->set_data(entry);
	if (previous_ptr->fore() != NULL) //�߰��ϴ� dnode�� dnode�� dnode ������ ��
	{
		insert_ptr->set_fore(previous_ptr->fore());
		insert_ptr->set_back(previous_ptr);
		previous_ptr->set_fore(insert_ptr);
		insert_ptr->fore()->set_back(insert_ptr);
	}
	else //�߰��ϴ� dnode�� �� ���� ��
	{
		insert_ptr->set_fore(NULL);
		previous_ptr->set_fore(insert_ptr);
		insert_ptr->set_back(previous_ptr);
		//tail_ptr = insert_ptr;  //�̰� �����غ�����
	}
}

dnode* list_search(dnode* head_ptr, const dnode::value_type& target) //���ϴ� data_field�� �� dnode�� ã�� �Լ�(dnode�� ������ �ٲ� �� ����)
{
	dnode* cursor;

	for (cursor = head_ptr; cursor != NULL; cursor = cursor->fore())
	{
		if (target == cursor->data())
			return cursor;
		return NULL;
	}
	return NULL;
}

const dnode* list_search(const dnode* head_ptr, const dnode::value_type& target) //���ϴ� data_field�� �� dnode�� ã�� �Լ�(dnode�� ������ �ٲ� �� ����)
{
	const dnode* cursor;

	for (cursor = head_ptr; cursor != NULL; cursor = cursor->fore())
	{
		if (target == cursor->data())
			return cursor;
		return NULL;
	}
}

dnode* list_locate(dnode* head_ptr, size_t position) //dnode�� ��ġ�� �ް� �� ��ġ�� �ִ� dnode�� ��ȯ�ϴ� �Լ�(dnode�� ������ �ٲ� �� ����)
{
	dnode* cursor = head_ptr;
	size_t i;
	assert(0 < position);
	for (i = 1; (cursor != NULL && i < position); ++i)
		cursor = cursor->fore();
	return cursor;
}

const dnode* list_locate(const dnode* head_ptr, size_t position) //dnode�� ��ġ�� �ް� �� ��ġ�� �ִ� dnode�� ��ȯ�ϴ� �Լ�(dnode�� ������ �ٲ� �� ����)
{
	const dnode* cursor = head_ptr;
	size_t i;
	assert(0 < position);
	for (i = 1; (cursor != NULL && i < position); ++i)
		cursor = cursor->fore();
	return cursor;
}

void list_copy(const dnode* source_ptr, dnode*& head_ptr, dnode*& tail_ptr) //�Է¹��� dnode�� ��°�� �����Ͽ� �Ȱ��� �ϳ� �� ����� �Լ�
{
	head_ptr = NULL;
	tail_ptr = NULL;
	if (source_ptr == NULL) //�Է¹��� dnode�� ���� ������ ���� ��
		return;
	list_head_insert(head_ptr, source_ptr->data());
	tail_ptr = head_ptr;
	source_ptr = source_ptr->fore();
	while (source_ptr != NULL) //������ dnode�� ������ �� ���� �ݺ�
	{
		list_insert(tail_ptr, source_ptr->data());
		tail_ptr = tail_ptr->fore();
		source_ptr = source_ptr->fore();
	}
}

void list_head_remove(dnode*& head_ptr) //�� ���� dnode�� �����ϴ� �Լ�
{
	dnode* remove_ptr;

	if (head_ptr == NULL) //�Է¹��� dnode�� ���� ������ ���� ��
		return;
	remove_ptr = head_ptr;
	head_ptr = head_ptr->fore();
	head_ptr->set_back(NULL);
	delete remove_ptr;
}

void list_remove(dnode* previous_ptr) //dnode�� dnode���̿� �ִ� dnode�� �����ϴ� �Լ�
{
	dnode* remove_ptr;

	remove_ptr = previous_ptr->fore();
	previous_ptr->set_fore(remove_ptr->fore());
	previous_ptr->fore()->set_back(remove_ptr->back());
	delete remove_ptr;
}

void list_clear(dnode*& head_ptr) //��� dnode�� �����ϴ� �Լ�
{
	while (head_ptr != NULL)
		list_head_remove(head_ptr);
}

template <class Item>
class stack
{
public:
	
	typedef std::size_t size_type;
	typedef Item value_type;
	
	stack();
	stack(const stack& source);
	~stack();
	
	void push(const Item& entry);
	void pop();
	Item top();
	const Item top() const;
	size_type size() const
	{
		return list_length(top_ptr);
	}
	bool empty() const { return (top_ptr == NULL); }
	void operator =(const stack& source);

private:
	dnode* top_ptr;  // top stack�� ����Ű�� ������
};

template<class Item>
stack<Item>::stack() {		//������
	top_ptr = NULL;
}

template<class Item>
stack<Item>::stack(const stack<Item>& source) {		//���� ������
	dnode* tail_ptr;
	list_copy(source.top_ptr, top_ptr, tail_ptr);
}

template<class Item>
stack<Item>::~stack() {		//���� ������
	list_clear(top_ptr);
}

template<class Item>
void stack<Item>::push(const Item& entry) { //stack�� push�ϴ� �Լ�
	list_head_insert(top_ptr, entry);
}

template<class Item>
void stack<Item>::pop() { //stack���� pop�ϴ� �Լ�
	assert(!empty());
	list_head_remove(top_ptr);
}

template<class Item>
Item stack<Item>::top() { //stack�� top�� ��ȯ�ϴ� �Լ�
	assert(!empty());
	return top_ptr->data();
}

template<class Item>
const Item stack<Item>::top() const {  //stack�� top�� ��ȯ�ϴ� �Լ�(const ����)
	assert(!empty());
	return top_ptr->data();
}

template<class Item>
void stack<Item>::operator=(const stack& source) {  //stack�� = operator�� stack�� �°� ������
	dnode* tail_ptr;
	if (this == &source)
		return;
	list_clear(top_ptr);
	list_copy(source.top_ptr, top_ptr, tail_ptr);
}

class evaluator {
public:
	string read_expression();
	string convert_to_postfix(string s);
	double evaluate_postfix(string s);
};

string evaluator::read_expression() {
	const char DECIMAL = '.';
	const char LEFT_PARENTHESIS = '(';
	const char RIGHT_PARENTHESIS = ')';
	
	double num;
	char c;
	string str;

	while (cin && cin.peek() != '\n') {
		if (cin.peek() == LEFT_PARENTHESIS || RIGHT_PARENTHESIS) {// ���� ���ڰ� '(' or ')' �̸� str�� �߰�
			cin >> c;
			str += c;
		}
		else if (isdigit(cin.peek()) || (cin.peek() == DECIMAL)) { // ���� ���ڰ� ���� or '.' �̸� str�� �߰�
			cin >> num;
			str += num;
		}
		else if (strchr("+-*/", cin.peek()) != NULL) {// ���� ���ڰ� �����ڸ� str�� �߰�
			cin >> c;
			str += c;
		}
		else
			cin.ignore(); // ������ �Էµ鿡 ���ؼ��� ����
	}
	return str;
}

bool comoper(char c1, char c2) { // �������� �켱������ ���ϴ� �Լ�
	if (c1 == c2) {				 // stack�� �� �ִ� �����ڰ� �켱������ �� ���ų�, ���� ��� true ��ȯ
		return true;
	}

	if (c1 == '+') {
		if (c2 == '-')
			return true;
	}

	if (c1 == '-') {
		if (c2 == '+')
			return true;
	}

	if (c1 == '*') {
		if (c2 == '+' || '-' || '/')
			return true;
	}

	if (c1 == '/') {
		if (c2 == '+' || '-' || '*')
			return true;
	}

	return false;
}

string evaluator::convert_to_postfix(string s) {
	const char DECIMAL = '.';
	const char LEFT_PARENTHESIS = '(';
	const char RIGHT_PARENTHESIS = ')';

	string str;
	string::iterator it;
	char c;
	stack<char> oper;

	for (int i = 0; i < s.length(); i++) {
		c = s[i];
		if (c == LEFT_PARENTHESIS) { // '(' ���� üũ��,'(' �̸� stack�� ����
			oper.push(c);
		}
		else if (isdigit(c) || (c == DECIMAL)) { // �������� üũ��, �����̸� ����Ʈ
			str += c;
		}
		else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) { // �������� üũ��, �����̸� ����Ʈ
			str += c;
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/') { //���������� üũ��, �������̸� stack���� ��Ȳ�� ����
			while (true) {												//�����ڸ� �����ϴ� ����� �ٸ��� ��
				if (!oper.empty() && oper.top() != LEFT_PARENTHESIS) {
					if (comoper(oper.top(), c)) {
						str += oper.top();
						oper.pop();
						break;
					}
				}
			}
			oper.push(c);
		}
		else if (c == RIGHT_PARENTHESIS) {
			while (oper.top() != LEFT_PARENTHESIS) {
				str += oper.top();
				oper.pop();
			}
			oper.pop();
		}
		else
			break;
	}
	oper.~stack();
	return str;
}

void evaluate(stack<double>& numbers, stack<char>& operations) // ���ÿ��� ������ postfix ������ �ϴ� �Լ�
{
	double num1, num2;

	num2 = numbers.top();
	numbers.pop();
	num1 = numbers.top();
	numbers.pop();
	switch (operations.top())
	{
	case '+': numbers.push(num2 + num1);
		break;
	case '-': numbers.push(num2 - num1);
		break;
	case '*': numbers.push(num2 * num1);
		break;
	case '/': numbers.push(num2 / num1);
		break;
	}
	operations.pop();
}

double evaluator::evaluate_postfix(string s) {
	const char DECIMAL = '.';
	const char RIGHT_PARENTHESIS = ')';

	stack<double> numbers;
	stack<char> operations;
	string::iterator it;

	for (it = s.begin(); it != s.end(); it++) { // string ������ �˻�
		if (isdigit(*it) || (*it == DECIMAL)) { // �������� üũ��, �����̸� numbers ���ÿ� push
			numbers.push(*it);
		}
		else if (*it == '+' || *it == '-' || *it == '*' || *it == '/') { // ���������� üũ��, �������̸� operations ���ÿ� push
			operations.push(*it);
		}
		else if (*it == RIGHT_PARENTHESIS) { // ������ ��ȣ�� ���
			evaluate(numbers, operations);
		}
	}
	return numbers.top();
}

int main(void) {
	string str;
	evaluator ev;
	cout << "Infix���� �Է����ּ��� >> ";
	str = ev.read_expression();
	cout << "String���� ��ȯ�� ���� : ";
	cout << str <<endl;
}