/*
 *  linux/kernel/syscalls_zombies.c
 *
 */

/*
 *  'syscalls_zombies.c' contains the help-routines for the 'syscalls_zombies' system call
 *  (see also entry.S and others).
 */
 
#include <linux/list.h>
#include <asm/current.h> // For the task_struct

// process list type
struct processes_list_t {
	pid_t pid;
	int max_z;	
    struct list_head list;
};
// process list instance
struct processes_list_t processes_list_head;
int is_list_init = 0;

static int add_process_to_list(int max_z, pid_t new_pid) {
	struct processes_list_t *ptr = (struct processes_list_t *)kmalloc(sizeof(struct processes_list_t));
	if (ptr == NULL)
		return -1;
	
	ptr->pid = new_pid;
	ptr->max_z = max_z;
	
	INIT_LIST_HEAD(&ptr->list);
	
	list_add(&ptr->list, processes_list_head);
	
	return 0;
}
static void process_list_init() {
	if (is_list_init == 0) {
		LIST_HEAD(&processes_list_head.list)
		is_list_init = 1;
	}
}
static int get_by_process_id(pid_t pid) {
	struct list_head *iter;
    struct processes_list_t *objPtr;
	
	__list_for_each(iter, processes_list_head) {
        objPtr = list_entry(iter, struct processes_list_t, list);
        if(objPtr->pid == pid) {
            return objPtr->max_z;
        }
    }

    return -1;
}

int set_max_zombies(int max_z, pid_t pid) {
	add_process_to_list(max_z, pid);
}
/*
get the current process max zombies
*/
int get_max_zombies() {
	return get_by_process_id(current->pid);
}