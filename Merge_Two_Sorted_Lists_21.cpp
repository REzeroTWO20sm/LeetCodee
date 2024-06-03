#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* mergedHead = new ListNode(0); 
        ListNode* tail = mergedHead;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                list1 = list1->next;
            } else {
                tail->next = list2;
                list2 = list2->next;
            }
            tail = tail->next;
        }

        if (list1 != nullptr) {
            tail->next = list1;
        }
        if (list2 != nullptr) {
            tail->next = list2;
        }

        mergedHead = mergedHead->next;
        mergedHead = radixSortLSD(mergedHead);

        return mergedHead;
    }

    int findMax(ListNode* arr) {
        int maxVal = arr->val;

        while (arr != nullptr) {
            if (arr->val > maxVal) {
                maxVal = arr->val;
            }
            arr = arr->next;
        }

        return maxVal;
    }

    int arr_size(ListNode* arr) {
        int count = 0;

        while (arr != nullptr) {
            count++;
            arr = arr->next;
        }

        return count;
    }

    ListNode* radixSortLSD(ListNode* arr) {
        if (arr == nullptr) {
            return arr;
        }
        int maxVal = findMax(arr);

        for (int exp = 1; maxVal / exp > 0; exp *= 10) {
            int n = arr_size(arr);

            std::vector<ListNode*> buckets(10, nullptr); 
            
            ListNode* current = arr;
            while (current != nullptr) {
                int digit = (current->val / exp) % 10;
                ListNode* next = current->next; 

                ListNode* temp = buckets[digit];
                buckets[digit] = current;
                current->next = temp; 

                current = next; 
            }

            ListNode* result = nullptr;
            ListNode* tail = nullptr;
            for (int i = 0; i < 10; i++) {
                if (buckets[i] != nullptr) {
                    if (result == nullptr) {
                        result = buckets[i];
                        tail = buckets[i];
                    } else {
                        tail->next = buckets[i];
                        tail = tail->next;
                    }
                }
            }
            if (tail != nullptr) {
                tail->next = nullptr;
            }
            arr = result;
        }
        return arr;
    }
};

int main() {
    ListNode* head1 = new ListNode(30);
    head1->next = new ListNode(5);
    // head1->next->next = new ListNode(2);
    // head1->next->next->next = new ListNode(4);
    // head1->next->next->next->next = new ListNode(5);

    ListNode* head2 = new ListNode(20);
    head2->next = new ListNode(11);
    // head2->next->next = new ListNode(2);
    // head2->next->next->next = new ListNode(4);
    // head2->next->next->next->next = new ListNode(5);

    Solution s;

    // s.radixSortLSD(head1);
    // s.radixSortLSD(head2);
    

    // std::cout << findMax(head) << std::endl;
    // std::cout << arr_size(head) << std::endl;
    
    ListNode* sortedHead = s.mergeTwoLists(s.radixSortLSD(head1),s.radixSortLSD(head2));

    while (sortedHead != nullptr) {
        std::cout << sortedHead->val << " ";
        sortedHead = sortedHead->next;
    }
    std::cout << std::endl;
    
    return 0;
}