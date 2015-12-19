    #include<stdio.h>

    #include<random>

    #include <time.h>

     

    #define MAX_VERTICES 30

    #define MAX_EDGES 10

     

    typedef unsigned char vertex;

     

    int main(){

     

        /*number of nodes in a graph*/

            std::random_device rd;
                std::mt19937 gen(rd());
                    std::uniform_int_distribution<> dis(1, 6);

        int numberOfVertices = dis(gen) % MAX_VERTICES;

     

        /*number of maximum edges a vertex can have*/


        int maxNumberOfEdges = dis(gen) % MAX_EDGES;

        /*graphs is 2 dimensional array of pointers*/

        if( numberOfVertices == 0)

            numberOfVertices++;

        vertex ***graph;

        printf("Total Vertices = %d, Max # of Edges = %d\n",numberOfVertices, maxNumberOfEdges);

     

        /*generate a dynamic array of random size*/

        if ((graph = (vertex ***) malloc(sizeof(vertex **) * numberOfVertices)) == NULL){

            printf("Could not allocate memory for graph\n");

            exit(1);

        }

     

        /*generate space for edges*/

        int vertexCounter = 0;

        /*generate space for vertices*/

        int edgeCounter = 0;

     

        for (vertexCounter = 0; vertexCounter < numberOfVertices; vertexCounter++){

            if ((graph[vertexCounter] = (vertex **) malloc(sizeof(vertex *) * maxNumberOfEdges)) == NULL){

                printf("Could not allocate memory for edges\n");

                exit(1);

            }

            for (edgeCounter = 0; edgeCounter < maxNumberOfEdges; edgeCounter++){

                if ((graph[vertexCounter][edgeCounter] = (vertex *) malloc(sizeof(vertex))) == NULL){

                    printf("Could not allocate memory for vertex\n");

                    exit(1);

                }

            }

        }

     

        /*start linking the graph. All vetrices need not have same number of links*/

        vertexCounter = 0;edgeCounter = 0;

        for (vertexCounter = 0; vertexCounter < numberOfVertices; vertexCounter++){

            printf("%d:\t",vertexCounter);

            for (edgeCounter=0; edgeCounter < maxNumberOfEdges; edgeCounter++){

                if (dis(gen)%2 == 1){ /*link the vertices*/

                    int linkedVertex = dis(gen) % numberOfVertices;

                    graph[vertexCounter][edgeCounter] = graph[linkedVertex];

                    printf("%d, ", linkedVertex);

                }

                else{ /*make the link NULL*/

                    graph[vertexCounter][edgeCounter] = NULL;

                }

            }

            printf("\n");

        }

        return 1;

    }
