#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "list.h"

#ifndef ANSI_C_LIST_H
    typedef struct node {
        int info;

        struct node *link;
    } NODE;
#endif //ANSI_C_LIST_H


NODE *start = NULL;
NODE *last = NULL;
int nodes = 0;

/**
 * Returns *start pointer (1st node)
 *
 * @return start
 */
NODE * getFirst() {

    return start;
}

/**
 * Returns *last pointer (Nth node). Loops all nodes, performs as O(n)
 *
 * @return last
 */
NODE * getLast() {

    last = NULL;
    NODE *first = start;

    while (!last) {

        if (!first->link) {
            last = first;
            break;
        }

        first = first->link;
    };

    return last;
}

/**
 * Creates 1st start node.
 * .. To initialize, use initialize()
 * .. To get start, use getFirst()
 *
 * -> Not updates nodes.
 *
 * @return start
 */
static NODE * create() {
    start = (NODE *)calloc(1, sizeof(NODE));

    if (!start) {
        perror("no allocation");
        return NULL;
    }

    start->info = -1;
    start->link = NULL;

    return start;
}

/**
 * Creates and adds first node.
 *
 * -> Set nodes=1.
 *
 * @param data for new node
 * @return start node
 */
static NODE * initialize(int data) {

    create();

    if (!start) {
        return NULL;
    }

    start->info = data;
    start->link = NULL;
    nodes = 1;

    return start;
}

/**
 * Appends new node to the end. If not initialized, then creates 1st node.
 *
 * -> Set nodes++.
 *
 * @param data
 * @return node that created
 */
NODE * append(int data) {

    if (!start)               //not initialized
        return initialize(data);

    //create new node
    NODE *tmp = (NODE *)calloc(1, sizeof(NODE));

    tmp->info = data;
    tmp->link = NULL;

    //find last node, and attach
    getLast()->link = tmp;
    nodes++;

    return tmp;
}

/**
 * Finds t in nodes while looping all nodes. O(n)
 *
 * -> Not updates nodes.
 *
 * @param t search data
 * @return if not found, -1 or (zero-based) node-index
 */
int search(int t) {
    if (!start) {
        perror("not initialized");
        return -1;
    }

    NODE *first = getFirst();
    int index = 0;
    bool found = false;

    do {
        if (first->info == t) {    //todo: compare function
            found = true;
            break;
        }

        index++;
        first = first->link;
    } while (first);

    return found ? index : -1;
}

/**
 * Finds t in nodes while looping all nodes. O(n)
 *
 * -> Not updates nodes.
 *
 * @param t search data
 * @return if not found, NULL or node
 */
NODE * search2(int t) {
    if (!start) {
        perror("not initialized");
        return NULL;
    }

    NODE *first = getFirst();
    bool found = false;
    int index = 0;

    do {
        if (first->info == t) {    //todo: compare function
            found = true;
            break;
        }

        index++;
        first = first->link;
    } while (first);

    return found ? first : NULL;

}

/**
 * Finds the node at index
 *
 * -> Not updates nodes.
 *
 * @param i (zero-based) node-index
 * @return if not found, NULL or the node
 */
NODE * searchByIndex(int i) {
    if (!start) {
        perror("not initialized");
        return NULL;
    }

    NODE *first = getFirst();
    int index = 0;

    do {

        if (index == i) {
            break;
        }

        index++;
        first = first->link;
    } while (first);

    return first;
}

/**
 * Access all nodes from *start to the end. Performs O(n).
 * Also, updates the node count.
 *
 * -> Set 0, then nodes++.
 *
 * @param node: start node
 */
void display(NODE *node) {

    if (!node) {
        perror("not initialized");
        return;
    }

    nodes = 0;
    do {
        nodes++;                                               //injected count update
        printf("info=%d, addr=%p\n", node->info, node->link);

        node = node->link;
    } while (node);    //means node != NULL
}

/**
 * Nodes count. Injected into code, so calculates fast O(1).
 *
 * @return nodes
 */
int count() {

    return nodes;                                             //return injected node.
}