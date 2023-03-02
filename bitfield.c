// A bitfield is ll[].
#define BITS 62
#define SET(BM, E) (BM[(E)/BITS] |= (1LL << (E)%BITS))
#define GET(BM, E) ((BM[(E)/BITS])&(1LL << ((E)%BITS)))
