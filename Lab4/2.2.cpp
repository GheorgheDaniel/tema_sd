//https://leetcode.com/problems/merge-k-sorted-lists/post-solution/?submissionId=2007573281

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        struct Comparator{
            bool operator ()(ListNode *f, ListNode *s) {
                return f->val > s->val;
            }
        };
        priority_queue<ListNode *, vector<ListNode *>, Comparator>pq;
        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] != nullptr)
            pq.push(lists[i]);
        }
        if(pq.empty()) return nullptr;
        ListNode *first;
        first = pq.top();
        ListNode *ans = first;
        if(first->next != nullptr) {
            pq.push(first->next);
        }
        pq.pop();
        while(!pq.empty()) {
            auto nod = pq.top();
            pq.pop();
            first->next = nod;
            first = nod;
            if(nod->next != nullptr) {
                pq.push(nod->next);
            }
        }
        return ans;
    }
};