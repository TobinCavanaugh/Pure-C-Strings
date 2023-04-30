#include <stdio.h>
#include "PureCStrings.c"
#include <time.h>
#include <sys/time.h>

#define var __auto_type
#define uint unsigned int
#define null NULL


double elapsed_time;

struct timeval end;
struct timeval start;

void StartTimer(){

    gettimeofday(&start, NULL);

}

void EndTimer(char * operation){
    gettimeofday(&end, NULL);
    double elapsed_time = (end.tv_sec - start.tv_sec) * 1000.0; // seconds to ms
    elapsed_time += (end.tv_usec - start.tv_usec) / 1000.0; // microseconds to ms

    printf("%s - %f ms\n", operation, elapsed_time);

}


int main() {

    const unsigned int iterations = 10000;
    const char * exampleString = "Sed ut perspiciatis, unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam eaque ipsa, quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt, explicabo. Nemo enim ipsam voluptatem, quia voluptas sit, aspernatur aut odit aut fugit, sed quia consequuntur magni dolores eos, qui ratione voluptatem sequi nesciunt, neque porro quisquam est, qui dolorem ipsum, quia dolor sit amet consectetur adipisci[ng] velit, sed quia non numquam [do] eius modi tempora inci[di]dunt, ut labore et dolore magnam aliquam quaerat voluptatem. Ut enim ad minima veniam, quis nostrum[d] exercitationem ullam corporis suscipit laboriosam, nisi ut aliquid ex ea commodi consequatur? [D]Quis autem vel eum i[r]ure reprehenderit, qui in ea voluptate velit esse, quam nihil molestiae consequatur, vel illum, qui dolorem eum fugiat, quo voluptas nulla pariatur? [33] At vero eos et accusamus et iusto odio dignissimos ducimus, qui blanditiis praesentium voluptatum deleniti atque corrupti, quos dolores et quas molestias excepturi sint, obcaecati cupiditate non provident, similique sunt in culpa, qui officia deserunt mollitia animi, id est laborum et dolorum fuga. Et harum quidem rerum facilis est et expedita distinctio. Nam libero tempore, cum soluta nobis est eligendi optio, cumque nihil impedit, quo minus id, quod maxime placeat, facere possimus, omnis voluptas assumenda est, omnis dolor repellendus. Temporibus autem quibusdam et aut officiis debitis aut rerum necessitatibus saepe eveniet, ut et voluptates repudiandae sint et molestiae non recusandae. Itaque earum rerum hic tenetur a sapiente delectus, ut aut reiciendis voluptatibus maiores alias consequatur aut perferendis doloribus asperiores repellat";

    PureString **replacements = malloc(iterations * sizeof(PureString *));

    for(int i = 0; i < iterations; i++){
        replacements[i] = PureString_Create(exampleString);
    }

    StartTimer();

    for(int i = 0; i < iterations; i++){
        PureString_Replace(replacements[i], ",", "-", SF_NONE);
    }

    EndTimer("replacement");


    StartTimer();

    for(int i = 0 ; i < iterations; i++){
        var a = PureString_Create(exampleString);
        PureString_Destroy(a);
    }

    EndTimer("creation and destruction");




    return 0;}
