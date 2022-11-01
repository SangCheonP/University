#include <cstdlib>
#include <iostream>

using namespace std;

template <class Item>
class set
{
public:
    typedef Item value_type;
    set() {  // Tree를 빈 값으로 저장
        for (int i = 0; i < MAXIMUM; i++) {
            data[i] == NULL;
            subset[i] == NULL;
        }
        subset[MAXIMUM + 1] = NULL;
    }

    set(const set& source) { // Tree가 들어오면 그 값으로 Tree를 초기화
        for (int i = 0; i < source->data_count; i++) {
            data[i] = source->data[i];
        }
        for (int i = 0; i < source->child_count; i++) {
            subset[i] = source->subset[i];
        }
    }

    bool insert(const Item& entry) { // Tree에 값을 추가하는 함수(loose insert와 fix_excess로 문제점을 해결)
        if (!loose_insert(entry))
            return false;
        if (data_count > MAXIMUM) {
            set* newroot[MAXIMUM + 1];
            newroot[0]->subset[0] = data;
            fix_excess(data);
        }
        return true;
    }
    
    size_t erase(const Item& target) { // Tree에 값을 삭제하는 함수(loose erase와 fix_shortage로 문제점을 해결)
        if (!loose_erase(target))
            return false;
        if ((data_count == 0) && (child_count == 1)) {
            int* ptr = &data;
            data = subset;
            delete ptr;
            fix_shortage(data);
        }
        return true;
    }
    
    size_t count(const Item& target) { // target값이 있는지 검사하는 함수
        int i;
        for (i = 0; i <= data_count; i++) {
            if (data[i] >= entry) {
                break;
            }
        }
        if (data[i] == target) {
            return 1;
        }
        else if (subset[i] -> data[i] == NULL) {
            return 0;
        }
        else {
            return subset[i]->count(target);
        }
    }

    void show_contents(int indent) { // Tree를 출력하는 함수
        int i;

        for (i = 0; i < indent; i++) {
            cout << "          ";
        }
        for (i = 0; i < data->data_count; i++) {
            cout << data[i]->subset[i] << " " << endl;
        }
        cout << endl;
        if (data[i] -> subset[i] != false) {
            for (i = 0; i < data->data_count + 1; i++) {
                show_contents(indent + 1);
            }
        }
    }

private:
    static const size_t MINIMUM = 200;
    static const size_t MAXIMUM = 2 * MINIMUM;
    size_t data_count;
    Item data[MAXIMUM + 1];
    size_t child_count;
    set* subset[MAXIMUM + 2];
    bool loose_insert(const Item& entry) { // MAXIMUM보다 1개 더 많게 하여 값을 추가
        int i;
        for (i = 0; i <= data_count; i++) {
            if (data[i] >= entry) {
                break;
            }
        }
        if (data[i] == entry)
            return false;
        else if (subset[i] -> data[i] == NULL) {
            for (int j = data_count - 2; j >= i; j--) {
                data[j + 1] = data[j];
            }
            data[i] = entry;
            return true;
        }
        else {
            bool b = subset[i]->loose_insert(entry);
            if (subset[i]->data_count > MAXIMUM) {
                fix_excess(i);
            }
            return b;
        }
    }
    bool loose_erase(const Item& target) { // MINIMUM보다 1개 더 적게 하여 작동시킴
        int i;
        for (i = 0; i <= data_count; i++) {
            if (data[i] >= target) {
                break;
            }
        }
        if (subset[i]->data[i] == NULL && data[i] != entry)
            return false;
        if (subset[i]->data[i] == NULL && data[i] == entry) {
            //entry지움
            return true;
        }
        if (subset[i]->data[i] != NULL && data[i] != entry) {
            bool b = subset[i]->loose_erase(target);
            if (subset[i]->data_count == MINIMUM - 1) {
                fix_shortage(i);
            }
        }
        if (subset[i]->data[i] != NULL && data[i] == entry) {
            subset[i]->remove_biggest(data[i]);
            if (subset[i]->data_count < MINIMUM) {
                fix_shortage(i);
            }
            return true;
        }
    }
    void remove_biggest(Item& removed_entry) { // 가장 큰 값을 삭제하는 함수
        if (subset == NULL) {
            //마지막 원소를 remove에 넣음
            data_count - 1;
        }
        if (subset != NULL) {
            subset[child_count - 1]->remove_biggest(removed_entry);
            if (subset[child_count - 1]->data_count < MINIMUM)
                fix_shortage(child_count - 1);
        }
    }
    void fix_excess(size_t i); // MAXIMUM보다 1개 많은 상황을 가운데 값을 올리고 2개로 나눠 해결
    void fix_shortage(size_t i); // MINIMUM보다 1개 적은 상황을 조건이 맞는 것과 합쳐 해결
};

int main(void) {
    set<int> a;
    a.insert(10);
    a.insert(3);
    a.insert(7);
    a.insert(6);
    a.insert(9);
    a.insert(2);
    a.insert(5);
    a.insert(1);
    a.show_contents(1);
}