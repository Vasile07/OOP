#include "oferta.h"
#include "ui.h"
#include "ofertaService.h"
#include "ofertaRepo.h"
#include "testOfertaRepo.h"
#include "testOfertaService.h"
#pragma warning(disable:4996)

void testAll(){
    test_destroy();
    testAdaugareOferta();
    testStergereOferta();
    testModificareOferta();
    testAdaugaOfertaService();
    testStergeOfertaService();
    testModificaOfertaService();
    testSortareDupaPretSiDestinatie();
    testFiltrareDupaCriteriu();
    test_lista_generica();
}

int main() {
    testAll();
    listaOferte *o = createOList();
    listaOferte *ListaUndo = createOList();
    run(o, ListaUndo);
}
