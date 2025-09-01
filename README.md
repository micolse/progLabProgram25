# ProgLabProgram25 — Visualizzatore Playlist Qt
## Classi principali
- **Song**  
  Rappresentazione della canzone con immagine, titolo e autore
- **Playlist**  
  Gestisce la lista di canzoni, tiene traccia dell'indice corrente, gestisce lo slideshow temporizzato e implementa il pattern Observer per notificare il PlDisplay
- **Subject**  
  Base per oggetti osservabili
- **Observer**  
  Interfaccia per gli oggetti che devono aggiornarsi
- **PlDisplay**  
  Widget per visualizzare la canzone corrente, aggiorna la visualizzazione tramite update() chiamato da Playlist
- **MainWindow**  
  GUI principale che contiene il display e i pulsanti per aggiungere, avviare e fermare lo slideshow delle canzoni

## Note
- Slideshow gestito con QTimer 
- Unit testing implementato con Google Test per Song e Playlist, provato su AddSong, NextSong e TempSlide  
