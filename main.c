//
//  main.c
//  road
//
//  Created by YUKE LI on 2019/9/18.
//  Copyright © 2019 YUKE LI. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

int main() {
    int len = 0, i = 0;
    printf("Please input length:");
    scanf("%d", &len);
    int road[1000] = {0};
    int new_road[1000] = {0};
    printf("Please input road status:");
    for (i = 0; i < len; i++) {
        scanf("%d", &road[i]);
    }
    int t = 0, j = 0, s = 0;
    printf("Please input time:");
    scanf("%d", &t);
    for (j = 0; j < t; j++) {
        int index = 0;
        for (s = 0; s < len; ) {
            index = (s + 1) % len;
            //int flag = 0;
            if (road[s] == 1) {
                if (road[index] == 0) {
                    new_road[s] = 0;
                    new_road[index] = 1;
                    s = s + 2;
                    //flag = 1;
                } else {
                    new_road[s] = 1;
                    s = s + 1;
                    //flag = 0;
                }
            } else {
                s = s + 1;
            }
        }
        int x = 0;
        for (x = 0; x < len; x++) {
            road[x] = new_road[x];
        }
        //road = new_road;
    }
    
    for (i = 0; i < len; i++) {
        printf("%d ", road[i]);
    }
    printf("\n");
    return 0;
}