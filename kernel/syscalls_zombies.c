/*
 *  linux/kernel/syscalls_zombies.c
 *  'syscalls_zombies.c' contains the help-routines for the 'syscalls_zombies' system call
 *  (see also entry.S and others).
 */
 
#include <linux/list.h>
#include <asm/current.h> // For the task_struct
#include <linux/sched.h>

int set_max_zombies(int max_z, pid_t pid) {
	if (max_z < 0) {
		return -EINVAL;
	}
	if (pid < 0) {
		return -ESRCH;
	}
	
	// TODO 
	
	return 0;
}

int get_max_zombies() {
	//TODO
	return 0;
}

int get_max_zombies_count(pid_t pid) {
	//TODO
	return 0;
}

pid_t get_zombie_pid(int n) {
	//TODO
	return 0;
}

int give_up_zombie(int n, pid_t adopter_pid) {
	//TODO
	return 0;
}