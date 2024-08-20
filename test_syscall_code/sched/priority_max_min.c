#include <stdio.h>
#include <stdlib.h>
#include <linux/sched.h>
#include <errno.h>

void print_priority_range(int policy) {
    int max_priority, min_priority;
    max_priority = sched_get_priority_max(policy);
    if (max_priority == -1) {
        perror("sched_get_priority_max");
        return;
    }
    
    min_priority = sched_get_priority_min(policy);
    if (min_priority == -1) {
        perror("sched_get_priority_min");
        return;
    }
    printf("Priority range: %d to %d\n", min_priority, max_priority);
}

int main() {
    printf("SCHED_FIFO:\n");
    print_priority_range(SCHED_FIFO);
    
    printf("\nSCHED_RR:\n");
    print_priority_range(SCHED_RR);
    
    printf("\nSCHED_OTHER:\n");
    print_priority_range(SCHED_OTHER);
    
    printf("\nSCHED_BATCH:\n");
    print_priority_range(SCHED_BATCH);
    
    printf("\nSCHED_IDLE:\n");
    print_priority_range(SCHED_IDLE);
    
    printf("\nSCHED_DEADLINE:\n");
    print_priority_range(SCHED_DEADLINE);
    
    return 0;
}
