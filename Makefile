NOM=PROJET_IN301
EDIT=Makefile slider.c afficher.c deplacer_balle.c lire_ecrire.c pop_puch.c run_slider.c editer_slider.c mes_phenetres_graphiques.c &
SDL=`sdl-config --cflags`



test: slider
	./slider $$(ls *.slider)

# Edition de liens
slider: slider.o lire_ecrire.o afficher.o deplacer_balle.o pop_puch.o editer_slider.o run_slider.o mes_phenetres_graphiques.o
	gcc  $^ -o slider -luvsqgraphics `sdl-config --libs` -lm -lSDL_ttf

# Compilation
slider.o: slider.c mes_types.h run_slider.h mes_phenetres_graphiques.h
	gcc -c -Wall $< $(SDL)
#Compilation
mes_phenetres_graphiques.o: mes_phenetres_graphiques.c mes_types.h lire_ecrire.h afficher.h editer_slider.h
	gcc -c -Wall $< $(SDL)
#Compilation
run_slider.o: run_slider.c mes_types.h lire_ecrire.h editer_slider.h afficher.h deplacer_balle.h mes_phenetres_graphiques.h
	gcc -c -Wall $< $(SDL)

#Compilation
editer_slider.o:editer_slider.c mes_types.h lire_ecrire.h afficher.h mes_phenetres_graphiques.h
	gcc -c -Wall $<  $(SDL)

#Compilation
pop_puch.o: pop_puch.c mes_types.h afficher.h
	gcc -c -Wall $< $(SDL)
#compilation
deplacer_balle.o:deplacer_balle.c afficher.h pop_puch.h
	gcc -c -Wall $< $(SDL)
# Compilation
lire_ecrire.o: lire_ecrire.c
	gcc -c -Wall $<

# Compilation
afficher.o: afficher.c
#	gcc -c -Wall   -I/usr/include/SDL -D_GNU_SOURCE=1 -D_REENTRANT  afficher.c
	gcc -c -Wall $(SDL)  $<

editeur:
	geany $(EDIT)

# Pour creer le zip a deposer sur e-campus
zip:
	rm -fr $(NOM)
	rm -f $(NOM).zip
	mkdir $(NOM)
	cp *.c $(NOM)
	cp *.h $(NOM)
	cp Makefile $(NOM)
#	cp -f *.slider $(NOM)
	zip $(NOM).zip $(NOM)/*
#	rm -fr $(NOM)



clean:
	rm -rf $(NOM)
	rm -f $(NOM).zip
	rm -f *.o
	rm -f slider
	
