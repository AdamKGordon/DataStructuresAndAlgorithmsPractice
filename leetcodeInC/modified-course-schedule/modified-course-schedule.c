int noLoopDfs(int courseNum, int** prerequisites, int* prerequisitesColSize, int *visited, int *map) {
    int i;
    if(visited[courseNum] == 2) { // already confirmed no cycles
        return 1;
    } else if (visited[courseNum] == 1) { // already visited (loop)
       return 0;
    } else if (visited[courseNum] == 0) {
        visited[courseNum] = 1;
    }

    for (i = 1; i < prerequisitesColSize[map[courseNum]]; i++) {
            if(!noLoopDfs(prerequisites[map[courseNum]][i], prerequisites, prerequisitesColSize, visited, map)) {
                return 0;
            }
    }
    visited[courseNum] = 2;    
    return 1;
}

bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize){
    int *map, *visited, i, j, mapIdx;
    map = (int *) malloc(sizeof(int)*numCourses);
    visited = (int *) malloc(sizeof(int)*numCourses);

    for(i = 0; i < numCourses; i++){
        map[i] = -1;
    }
    
    for (i = 0; i < numCourses; i++) {
        if (i<prerequisitesSize){
            map[prerequisites[i][0]] = i;
        } else {
            break;
        }
    }

    for (i = 0; i < numCourses; i++) {
        if (map[i] == -1){
            visited[i] = 2; // confirmed node w/o loop pre reqs
        } else {
            visited[i] = 0; // not visited
        }                   // 1 would be visited
    }
    
    for (i = 0; i < prerequisitesSize; i++) {
        mapIdx = map[i];
        if(mapIdx == -1) {
            continue;
        }
        if(!noLoopDfs(i, prerequisites, prerequisitesColSize, visited, map)) {
          return 0;
        }
    }        
    
    free(map);
    free(visited);
    return 1;        
}