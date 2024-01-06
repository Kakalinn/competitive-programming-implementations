// further testing is NEEDED, especially since it's a MACRO.
// tested: gold

// Useage:  queue(<name>, <max pushes>, <type>);
// Example: queue(q, 1000, int);
// Note:    Pushes do not count in "max pushes".
//          The declaration is the only strange (macro-y) call.
//          The "type" is very restricted. It must be able to index arrays.

#define queue(E, F, G) G E[(F) + 2]; E[0] = E[1] = 2
#define push(E, F) ((E)[(E)[1]++] = (F))
#define pop(E) ((E)[(E)[0]++])
#define peak(E) ((E)[(E)[0]])
#define empty(E) ((E)[0] == (E)[1])
