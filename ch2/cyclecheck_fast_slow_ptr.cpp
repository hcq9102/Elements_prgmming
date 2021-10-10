
// O(n) time complexity
// O(1) space __only use slow/fast/ptr pointer

/*两次遍历确定环的入口
 * 快慢指针：

第一次遍历，一快一慢，若相遇，只能确定有环，相遇点可能时环内任意位置；
第二次遍历，同速度，相遇点才为环入口点
注意循环的时候边界条件的判断~

 * */
//Definition for singly-linked list.
struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class HasCyc {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next == NULL) return NULL;
        ListNode *slow = head, *fast = head;
        // 边界条件的判断
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            //若找到环，则再次遍历找环入口点
            if(slow == fast){
                slow = head;
                while(slow != fast){
                    slow = slow->next;
                    fast = fast->next;
                }
                return fast;
            }
        }
        return NULL;
    }
};
