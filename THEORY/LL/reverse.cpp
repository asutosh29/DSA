#include <iostream>
#include <vector>
#include<set>

using namespace std;

// 1. Standard Interview Node Definition
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// 2. Testing Utility: Convert Vector to Linked List
ListNode* buildList(const vector<int>& nums) {
    if (nums.empty()) return nullptr;
    ListNode* head = new ListNode(nums[0]);
    ListNode* tail = head;
    for (size_t i = 1; i < nums.size(); ++i) {
        tail->next = new ListNode(nums[i]);
        tail = tail->next;
    }
    set<char> s;
    return head;
}

// 3. Testing Utility: Convert Linked List back to Vector
vector<int> listToVector(ListNode* head) {
    vector<int> result;
    while (head != nullptr) {
        result.push_back(head->val);
        head = head->next;
    }
    return result;
}

// 4. Testing Utility: Free memory
void freeList(ListNode* head) {
    while (head != nullptr) {
        ListNode* temp = head->next;
        delete head;
        head = temp;
    }
}

// ==========================================
// YOUR LOGIC GOES HERE
// ==========================================
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr) return head;

        ListNode* fast = head;
        ListNode* slow = head;

        while(n--){
            fast = fast->next;
        }
        if(fast == nullptr){ // the first node case...
            head = head->next;
            delete slow;
            return head;
        }
        while(fast->next != nullptr){
            slow = slow->next;
            fast = fast->next;
        }
        ListNode* temp = slow->next; // tricky while deleting the node itself
        slow->next = slow->next->next;
        delete temp;

        return head;
    }
};
// ==========================================

void runTest(int testNum, const vector<int>& input, int n, const vector<int>& expected) {
    Solution solver;
    ListNode* head = buildList(input);
    
    ListNode* result = solver.removeNthFromEnd(head, n);
    vector<int> actual = listToVector(result);
    
    if (actual == expected) {
        cout << "[PASS] Test Case " << testNum << endl;
    } else {
        cout << "[FAIL] Test Case " << testNum << endl;
        cout << "  Input:    ";
        for (int x : input) cout << x << " ";
        cout << "| n = " << n << endl;
        cout << "  Expected: ";
        for (int x : expected) cout << x << " ";
        cout << "\n  Got:      ";
        for (int x : actual) cout << x << " ";
        cout << endl;
    }
    
    // Cleanup
    freeList(result);
}

int main() {
    // --- TEST CASE 1: Standard Middle Removal ---
    // Remove 2nd from end (which is 4). Expected: [1, 2, 3, 5]
    runTest(1, {1, 2, 3, 4, 5}, 2, {1, 2, 3, 5});

    // --- TEST CASE 2: Remove the Last Node ---
    // Remove 1st from end (which is 5). Expected: [1, 2, 3, 4]
    runTest(2, {1, 2, 3, 4, 5}, 1, {1, 2, 3, 4});

    // --- TEST CASE 3: Remove the HEAD Node (Crucial Edge Case) ---
    // Remove 5th from end (which is 1). Expected: [2, 3, 4, 5]
    runTest(3, {1, 2, 3, 4, 5}, 5, {2, 3, 4, 5});

    // --- TEST CASE 4: Single Node List ---
    // Remove 1st from end (which is 1). Expected: []
    runTest(4, {1}, 1, {});

    // --- TEST CASE 5: Two Node List, remove Head ---
    runTest(5, {1, 2}, 2, {2});

    return 0;
}