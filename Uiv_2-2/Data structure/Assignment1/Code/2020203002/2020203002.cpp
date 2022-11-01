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
		insert_ptr->set_back(previous_ptr);//////////////////????
		previous_ptr->set_fore(insert_ptr);
		insert_ptr->fore()->set_back(insert_ptr);
	}
	else //추가하는 dnode가 맨 뒤일 때
	{
		insert_ptr->set_fore(NULL);
		previous_ptr->set_fore(insert_ptr);
		insert_ptr->set_back(previous_ptr);
		tail_ptr = insert_ptr;  //이거 생각해봐야함
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

class bag
{
public:
	typedef size_t size_type;
	typedef double value_type;

	bag();
	bag(const bag& source);
	~bag();
	void operator =(const bag& source);
	bool operator ==(const bag& source);
	bool operator !=(const bag& source);
	void operator +=(const bag& addend);
	bool erase_one(const value_type& target);
	size_type count(const value_type& target) const;
	void insert(const value_type& entry);
	void show_contents();
	void sort();
	size_type size()const { return many_nodes; }
private:
	dnode* head_ptr;
	size_type many_nodes;
};

bag operator+(const bag& b1, const bag& b2) // bag 2개를 받아 하나씩 +=로 저장하여 새로운 bag으로 반환하게 하는 함수
{

	bag out;

	out += b1;
	out += b2;
	return out;
}

bag::bag() //생성자로 초기 값을 설정하는 함수
{
	head_ptr = NULL;
	many_nodes = 0;
}

bag::bag(const bag& source) //복사 생성자로 받은 것을 똑같이 하나 더 만드는 함수
{
	dnode* tail_ptr;
	list_copy(source.head_ptr, head_ptr, tail_ptr);
	many_nodes = source.many_nodes;
}

bag::~bag() //bag을 없애는 함수
{
	list_clear(head_ptr);
	many_nodes = 0;
}

void bag::operator =(const bag& source) //입력받은 source처럼 복사하여 bag을 만드는 함수
{
	dnode* tail_ptr;
	if (this == &source)
		return;
	list_clear(head_ptr);
	many_nodes = 0;
	list_copy(source.head_ptr, head_ptr, tail_ptr);
	many_nodes = source.many_nodes;
}

bool bag::operator ==(const bag& source) //입력받은 bag과 가지고 있는 bag이 같은 지를 검사하는 함수
{
	dnode* ptr1 = head_ptr;
	dnode* ptr2 = source.head_ptr;
	if ((ptr1 == NULL) && (ptr2 == NULL)) //두 bag에 모두 값이 없을 때
		return true;
	else if ((ptr1 == NULL) || (ptr2 == NULL)) // 둘 중에 하나만 값이 있을 때
		return false;
	else //두 bag에 모두 값들이 들어있을 때 같은지를 비교
	{
		while (ptr1 != NULL)
		{
			if (ptr1->data() == ptr2->data())
			{
				ptr1 = ptr1->fore();
				ptr2 = ptr2->fore();
			}
			else
				return false;
		}
		return true;
	}
}

bool bag::operator !=(const bag& source) //입력받은 bag과 가지고 있는 bag이 다른지를 검사하는 함수(==함수와 반환값만 반대로 설정)
{
	dnode* ptr1 = head_ptr;
	dnode* ptr2 = source.head_ptr;
	if ((ptr1 == NULL) && (ptr2 == NULL))//두 bag에 모두 값이 없을 때
		return false;
	else if ((ptr1 == NULL) || (ptr2 == NULL)) // 둘 중에 하나만 값이 있을 때
		return true;
	else//두 bag에 모두 값들이 들어있을 때 다른지를 비교
	{
		while (ptr1 != NULL)
		{
			if (ptr1->data() == ptr2->data())
			{
				ptr1 = ptr1->fore();
				ptr2 = ptr2->fore();
			}
			else
				return true;
		}
		return false;
	}
}

void bag::operator+=(const bag& addend) //다른 bag의 값을 이미 가지고 있는 bag에 추가하여 연결시키는 함수
{
	dnode* copy_head_ptr;
	dnode* copy_tail_ptr;
	if (addend.many_nodes > 0)
	{
		list_copy(addend.head_ptr, copy_head_ptr, copy_tail_ptr);
		copy_tail_ptr->set_fore(head_ptr);
		copy_tail_ptr->fore()->set_back(copy_tail_ptr);
		head_ptr = copy_head_ptr;
		many_nodes += addend.many_nodes;
	}
}

bool bag::erase_one(const value_type& target) //입력받은 data가 bag에 있으면 하나를 제거하고, head_ptr에 있는 data값을 가져오고 맨 앞 dnode를 하나 지우는 함수
{
	dnode* target_ptr;
	target_ptr = list_search(head_ptr, target);
	if (target_ptr == NULL)
		return false;
	target_ptr->set_data(head_ptr->data());
	list_head_remove(head_ptr);
	--many_nodes;
	return true;
}

bag::size_type bag::count(const value_type& target) const //입력받은 data가 bag에 몇개있는지 세는 함수
{
	size_type answer;
	const dnode* cursor;

	answer = 0;
	cursor = list_search(head_ptr, target);
	while (cursor != NULL)
	{
		++answer;
		cursor = cursor->fore();
		cursor = list_search(cursor, target);
	}
	return answer;
}

void bag::insert(const value_type& entry) //bag에 하나의 data를 맨 앞에 추가하는 함수
{
	list_head_insert(head_ptr, entry);
	++many_nodes;
}

void bag::show_contents() //지금 가지고 있는 bag을 출력하는 함수
{
	dnode* out = head_ptr;
	cout << "bag을 출력합니다. \n";
	if (head_ptr == NULL)
	{
		cout << "bag이 비어있습니다." << endl << endl;
		return;
	}
	while (out != NULL)
	{
		cout << " " << out->data() << " ";
		out = out->fore();
	}
	cout << endl << endl;
}

void bag::sort() //bag의 data를 오름차순으로 정렬하는 함수
{
	dnode* cur = head_ptr;
	dnode* next = NULL;
	if (head_ptr == NULL) //버블정렬을 bag버전으로 바꿈
		return;
	else
	{
		while (cur != NULL)
		{
			next = cur->fore();

			while (next != NULL)
			{
				if (cur->data() > next->data())
				{
					double temp = cur->data();
					cur->set_data(next->data());
					next->set_data(temp);
				}
				next = next->fore();
			}
			cur = cur->fore();
		}
	}
}

int main(void)
{
	bag str1, str2;

	str1.show_contents(); //빈 bag을 보여줌
	str1.insert(4);	// 각각의 숫자를 bag에 넣음
	str1.insert(7);
	str1.insert(2);
	str1.insert(1);
	str1.insert(3);
	str1.show_contents(); // 잘 넣어졌는지 확인


	str2.show_contents();
	str2.insert(6);
	str2.insert(2);
	str2.insert(2);
	str2.show_contents();

	cout << str2.count(2) << "개" << endl << endl; //2가 몇개 들어가 있는지 출력

	str1 += str2;  // str1에 str2을 복사해 넣어 합침
	str1.show_contents();

	str1.sort(); //오름차순으로 정렬
	str1.show_contents();

	if (str1 == str2) // 같은지를 비교
		cout << "두 bag은 같다" << endl;
	else
		cout << "두 bag은 다르다" << endl;

	str1.~bag(); //bag을 삭제
	str1.show_contents(); // 아무것도 출력을 하지 않음

	return 0;
}