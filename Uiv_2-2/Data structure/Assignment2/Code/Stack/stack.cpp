#include <cstdlib>
#include <cassert>
#include <iostream>

using namespace std;

class dnode {
public:
	typedef double value_type; //double을 typedef로 value_type으로 재정의

	dnode(const value_type& init_data = value_type(), dnode* init_fore = NULL, dnode* init_back = NULL) //data는 double의 값, fore, back은 NULL로 초기화하는 생성자
	{
		data_field = init_data;
		link_fore = init_fore;
		link_back = init_back;
	}

	void set_data(const value_type& new_data) //data를 받아 맴버변수 data_field에 저장
	{
		data_field = new_data;
	}

	void set_fore(dnode* new_fore) //new_fore을 받아 다음 dnode를 가르키는 link_fore에 저장
	{
		link_fore = new_fore;
	}

	void set_back(dnode* new_back) //new_back을 받아 전 dnode를 가르키는 link_back에 저장
	{
		link_back = new_back;
	}

	value_type data() const //data_field에 저장된 값을 반환
	{
		return data_field;
	}

	const dnode* fore() const //link_fore에 저장된 값을 반환(변경할 수 없음)
	{
		return link_fore;
	}

	dnode* fore() //link_fore에 저장된 값을 반환(값 변경가능)
	{
		return link_fore;
	}

	const dnode* back() const //link_back에 저장된 값을 반환(변경할 수 없음)
	{
		return link_back;
	}

	dnode* back() //link_back에 저장된 값을 반환(값 변경가능)
	{
		return link_back;
	}

private:
	value_type data_field; //각각 데이터, 다음 dnode, 전 dnode로 가는 맴버함수를 선언
	dnode* link_fore;
	dnode* link_back;
};

dnode* head_ptr = NULL;
dnode* tail_ptr = NULL;

size_t list_length(const dnode* head_ptr) //받은 dnode의 길이를 반환하는 함수
{
	size_t answer = 0;
	const dnode* cursor;
	for (cursor = head_ptr; cursor != NULL; cursor = cursor->fore()) {
		++answer;
	}
	return answer;
}

void list_head_insert(dnode*& head_ptr, const dnode::value_type& entry) //dnode의 가장 앞에 dnode를 하나 추가하는 함수
{
	dnode* insert_ptr = new dnode();
	insert_ptr->set_fore(head_ptr);
	insert_ptr->set_data(entry);
	insert_ptr->set_back(NULL);
	if (head_ptr != NULL) //만약 이미 dnode가 하나라도 존재하여 맨 앞에 dnode를 추가해야 할 때를 고려
	{
		head_ptr->set_back(insert_ptr);
	}
	head_ptr = insert_ptr;
}

void list_insert(dnode* previous_ptr, const dnode::value_type& entry) //dnode와 dnode사이에 새로운 dnode를 추가하는 함수
{
	dnode* insert_ptr;

	insert_ptr = new dnode;
	insert_ptr->set_data(entry);
	if (previous_ptr->fore() != NULL) //추가하는 dnode가 dnode와 dnode 사이일 때
	{
		insert_ptr->set_fore(previous_ptr->fore());
		insert_ptr->set_back(previous_ptr);
		previous_ptr->set_fore(insert_ptr);
		insert_ptr->fore()->set_back(insert_ptr);
	}
	else //추가하는 dnode가 맨 뒤일 때
	{
		insert_ptr->set_fore(NULL);
		previous_ptr->set_fore(insert_ptr);
		insert_ptr->set_back(previous_ptr);
		//tail_ptr = insert_ptr;  //이거 생각해봐야함
	}
}

dnode* list_search(dnode* head_ptr, const dnode::value_type& target) //원하는 data_field가 들어간 dnode를 찾는 함수(dnode의 값들을 바꿀 수 있음)
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

const dnode* list_search(const dnode* head_ptr, const dnode::value_type& target) //원하는 data_field가 들어간 dnode를 찾는 함수(dnode의 값들을 바꿀 수 없음)
{
	const dnode* cursor;

	for (cursor = head_ptr; cursor != NULL; cursor = cursor->fore())
	{
		if (target == cursor->data())
			return cursor;
		return NULL;
	}
}

dnode* list_locate(dnode* head_ptr, size_t position) //dnode의 위치를 받고 그 위치에 있는 dnode를 반환하는 함수(dnode의 값들을 바꿀 수 있음)
{
	dnode* cursor = head_ptr;
	size_t i;
	assert(0 < position);
	for (i = 1; (cursor != NULL && i < position); ++i)
		cursor = cursor->fore();
	return cursor;
}

const dnode* list_locate(const dnode* head_ptr, size_t position) //dnode의 위치를 받고 그 위치에 있는 dnode를 반환하는 함수(dnode의 값들을 바꿀 수 없음)
{
	const dnode* cursor = head_ptr;
	size_t i;
	assert(0 < position);
	for (i = 1; (cursor != NULL && i < position); ++i)
		cursor = cursor->fore();
	return cursor;
}

void list_copy(const dnode* source_ptr, dnode*& head_ptr, dnode*& tail_ptr) //입력받은 dnode를 통째로 복사하여 똑같이 하나 더 만드는 함수
{
	head_ptr = NULL;
	tail_ptr = NULL;
	if (source_ptr == NULL) //입력받은 dnode가 가진 정보가 없을 때
		return;
	list_head_insert(head_ptr, source_ptr->data());
	tail_ptr = head_ptr;
	source_ptr = source_ptr->fore();
	while (source_ptr != NULL) //마지막 dnode에 도달할 때 까지 반복
	{
		list_insert(tail_ptr, source_ptr->data());
		tail_ptr = tail_ptr->fore();
		source_ptr = source_ptr->fore();
	}
}

void list_head_remove(dnode*& head_ptr) //맨 앞의 dnode를 제거하는 함수
{
	dnode* remove_ptr;

	if (head_ptr == NULL) //입력받은 dnode가 가진 정보가 없을 때
		return;
	remove_ptr = head_ptr;
	head_ptr = head_ptr->fore();
	head_ptr->set_back(NULL);
	delete remove_ptr;
}

void list_remove(dnode* previous_ptr) //dnode와 dnode사이에 있는 dnode를 제거하는 함수
{
	dnode* remove_ptr;

	remove_ptr = previous_ptr->fore();
	previous_ptr->set_fore(remove_ptr->fore());
	previous_ptr->fore()->set_back(remove_ptr->back());
	delete remove_ptr;
}

void list_clear(dnode*& head_ptr) //모든 dnode를 제거하는 함수
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
	dnode* top_ptr;  // top stack을 가르키는 포인터
};

template<class Item>
stack<Item>::stack() {		//생성자
	top_ptr = NULL;
}

template<class Item>
stack<Item>::stack(const stack<Item>& source) {		//복사 생성자
	dnode* tail_ptr;
	list_copy(source.top_ptr, top_ptr, tail_ptr);
}

template<class Item>
stack<Item>::~stack() {		//복사 생성자
	list_clear(top_ptr);
}

template<class Item>
void stack<Item>::push(const Item& entry) { //stack에 push하는 함수
	list_head_insert(top_ptr, entry);
}

template<class Item>
void stack<Item>::pop() { //stack에서 pop하는 함수
	assert(!empty());
	list_head_remove(top_ptr);
}

template<class Item>
Item stack<Item>::top() { //stack의 top을 반환하는 함수
	assert(!empty());
	return top_ptr->data();
}

template<class Item>
const Item stack<Item>::top() const {  //stack의 top을 반환하는 함수(const 버전)
	assert(!empty());
	return top_ptr->data();
}

template<class Item>
void stack<Item>::operator=(const stack& source) {  //stack의 = operator를 stack에 맞게 재정의
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
		if (cin.peek() == LEFT_PARENTHESIS || RIGHT_PARENTHESIS) {// 읽은 문자가 '(' or ')' 이면 str에 추가
			cin >> c;
			str += c;
		}
		else if (isdigit(cin.peek()) || (cin.peek() == DECIMAL)) { // 읽은 문자가 숫자 or '.' 이면 str에 추가
			cin >> num;
			str += num;
		}
		else if (strchr("+-*/", cin.peek()) != NULL) {// 읽은 문자가 연산자면 str에 추가
			cin >> c;
			str += c;
		}
		else
			cin.ignore(); // 나머지 입력들에 대해서는 무시
	}
	return str;
}

bool comoper(char c1, char c2) { // 연산자의 우선순위를 비교하는 함수
	if (c1 == c2) {				 // stack에 들어가 있는 연산자가 우선순위가 더 높거나, 같을 경우 true 반환
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
		if (c == LEFT_PARENTHESIS) { // '(' 인지 체크후,'(' 이면 stack에 저장
			oper.push(c);
		}
		else if (isdigit(c) || (c == DECIMAL)) { // 숫자인지 체크후, 숫자이면 프린트
			str += c;
		}
		else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) { // 변수인지 체크후, 변수이면 프린트
			str += c;
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/') { //연산자인지 체크후, 연산자이면 stack안의 상황에 따라
			while (true) {												//연산자를 저장하는 방법을 다르게 함
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

void evaluate(stack<double>& numbers, stack<char>& operations) // 스택에서 꺼내서 postfix 연산을 하는 함수
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

	for (it = s.begin(); it != s.end(); it++) { // string 끝까지 검사
		if (isdigit(*it) || (*it == DECIMAL)) { // 숫자인지 체크후, 숫자이면 numbers 스택에 push
			numbers.push(*it);
		}
		else if (*it == '+' || *it == '-' || *it == '*' || *it == '/') { // 연산자인지 체크후, 연산자이면 operations 스택에 push
			operations.push(*it);
		}
		else if (*it == RIGHT_PARENTHESIS) { // 오른쪽 괄호면 계산
			evaluate(numbers, operations);
		}
	}
	return numbers.top();
}

int main(void) {
	string str;
	evaluator ev;
	cout << "Infix식을 입력해주세요 >> ";
	str = ev.read_expression();
	cout << "String으로 변환한 수식 : ";
	cout << str <<endl;
}