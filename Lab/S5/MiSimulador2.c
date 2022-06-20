#include "CacheSim.h"
#include <stdio.h>

/* Posa aqui les teves estructures de dades globals
 * per mantenir la informacio necesaria de la cache
 * */

 struct cache{
   unsigned int valid;
   unsigned int tag;
 };

struct cache v[128];

int lru[64];

int total_hits;
int total_references;

/* La rutina init_cache es cridada pel programa principal per
 * inicialitzar la cache.
 * La cache es inicialitzada al comen�ar cada un dels tests.
 * */
void init_cache ()
{
    totaltime=0.0;
	/* Escriu aqui el teu codi */

  for (int i = 0; i < 128; ++i) {
    v[i].valid = 0;
    v[i].tag = 0;
  }

  for (int i = 0; i < 64; ++i) {
    lru[i] = 0;
  }

  total_hits = 0;
  total_references = 0;

}

/* La rutina reference es cridada per cada referencia a simular */
void reference (unsigned int address)
{
	unsigned int byte;
	unsigned int bloque_m;
	unsigned int conj_mc;
	unsigned int via_mc;
	unsigned int tag;
	unsigned int miss;	   // boolea que ens indica si es miss
	unsigned int replacement;  // boolea que indica si es reempla�a una linia valida
	unsigned int tag_out;	   // TAG de la linia reempla�ada
	float t1,t2;		// Variables per mesurar el temps (NO modificar)

	t1=GetTime();
	/* Escriu aqui el teu codi */

  byte = address%32;
  bloque_m = address/32;
  conj_mc = bloque_m%64;
  tag = bloque_m/64;

  if (v[conj_mc].valid == 0) {
    v[conj_mc].valid = 1;
    v[conj_mc].tag = tag;
    miss = true;
    replacement = false;
    lru[conj_mc] = 0;
    via_mc = 0;
  }
  else if (v[conj_mc].tag == tag) {
    miss = false;
    replacement = false;
    lru[conj_mc] = 0;
    via_mc = 0;
  }
  else if (v[conj_mc + 64].valid == 0) {
    v[conj_mc + 64].valid = 1;
    v[conj_mc + 64].tag = tag;
    miss = true;
    replacement = false;
    lru[conj_mc] = 1;
    via_mc = 1;
  }
  else if (v[conj_mc + 64].tag == tag) {
    miss = false;
    replacement = false;
    lru[conj_mc] = 1;
    via_mc = 1;
  }
  else if (lru[conj_mc] == 1) {
    tag_out = v[conj_mc].tag;
    v[conj_mc].tag = tag;
    miss = true;
    replacement = true;
    via_mc = 0;
    lru[conj_mc] = 0;
  }
  else {
    tag_out = v[conj_mc + 64].tag;
    v[conj_mc + 64].tag = tag;
    miss = true;
    replacement = true;
    via_mc = 1;
    lru[conj_mc] = 1;
  }


    ++total_references;
    if (!miss) ++total_hits;

	/* La funcio test_and_print escriu el resultat de la teva simulacio
	 * per pantalla (si s'escau) i comproba si hi ha algun error
	 * per la referencia actual. Tamb� mesurem el temps d'execuci�
	 * */
	t2=GetTime();
	totaltime+=t2-t1;
	test_and_print2 (address, byte, bloque_m, conj_mc, via_mc, tag,
			miss, replacement, tag_out);
}

/* La rutina final es cridada al final de la simulacio */
void final ()
{
 	/* Escriu aqui el teu codi */
  printf("Instruccions %d\n", total_references);
  printf("Hits %d\n", total_hits);
  printf("Misses %d\n\n", total_references - total_hits);

}
