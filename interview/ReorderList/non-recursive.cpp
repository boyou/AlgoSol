#include <cstdio>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


void output(ListNode *head) {
    for (ListNode *cur = head; cur != NULL; cur = cur->next) {
        printf(" %d", cur->val);
    }
    printf("\n");
}

class Solution {
public:
    void reorderList(ListNode *head) {
        ListNode *mid = split(head);
        ListNode *nh = reverse(mid);
        merge(head, nh, mid);
        output(head);
    }
private:
    ListNode* split(ListNode *head) {
        ListNode *p1 = head;
        ListNode *p2 = head;
        while (p1 != NULL) {
            p2 = p2->next;
            p1 = p1->next;
            if (p1 != NULL) {
                p1 = p1->next;
            }
        }
        return p2;
    }
    ListNode* reverse(ListNode *head) {
        ListNode *prev = NULL;
        ListNode *cur = head;
        while (cur != NULL) {
            ListNode *tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        return prev;
    }
    void merge(ListNode *h1, ListNode *h2, ListNode *mid) {
        ListNode *prev = NULL;
        while (h2 != NULL) {
            if (prev != NULL) {
                prev->next = h1;
            }
            prev = h1;
            h1 = h1->next;
            prev->next = h2;
            prev = h2;
            h2 = h2->next;
        }
        // the next pointer of the last element of the first sublist
        // points to mid
        if (h1 != mid) {
            if (prev != NULL) {
                prev->next = h1;
            }
            h1->next = NULL;
        }
    }
};

int main() {
    int const N = 6;
    // build several sample list of odd and even lengths
    ListNode* h[N + 1];
    for (int l = 0; l <= N; ++l) {
        h[l] = NULL;
        for (int i = l; i > 0; --i) {
            h[l] = new ListNode(i, h[l]);
        }
    }
    for (int l = 0; l <= N; ++l) {
        output(h[l]);
    }
    // execution
    Solution sol;
    for (int l = 0; l <= N; ++l) {
        sol.reorderList(h[l]);
    }
    return 0;
}
