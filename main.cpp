#include <gtkmm.h>

int main(int argc, char *argv[])
{
Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "com.gtkmm.tutorial2.base");

    Gtk::Window window;

    window.set_default_size(400, 200);
    window.set_title("Gtkmm Example");

    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL,0)); //stworzenie nowego kontenera typu box z orientacją pionową
    window.add(*vbox); //dodanie vbox do okna głównego

    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar()); //utworzenie paska menu
    vbox ->pack_start(*menubar,Gtk::PACK_SHRINK,0); //dodanie paska do vboxa



    Gtk::MenuItem *menuitem_plik = Gtk::manage(new Gtk::MenuItem("_Plik",true)); //tworzenie menu Plik
    menubar->append(*menuitem_plik);

    Gtk::Menu *menuPlik = Gtk::manage(new Gtk::Menu()); //tworzenie kontenera na pozycje menu
    menuitem_plik->set_submenu(*menuPlik);//dodanie kontenera do menu Plik

    Gtk::MenuItem *menuitem_open = Gtk::manage(new Gtk::MenuItem("_Nowy",true)); //tworzenie pozycji Nowy dla menu Plik
    menuPlik->append(*menuitem_open);

    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Wyjdź",true)); //tworzenie pozycji Wyjdź dla menu Plik
    menuPlik->append(*menuitem_quit);

    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("Po_moc",true)); //tworzenie menu Pomoc
    menubar->append(*menuitem_help);

    Gtk::Menu *menuPomoc = Gtk::manage(new Gtk::Menu()); //tworzenie kontenera dla menu pomoc
    menuitem_help->set_submenu(*menuPomoc);

    Gtk::MenuItem *menuitem_Oprogramie = Gtk::manage(new Gtk::MenuItem("O pr_ogramie",true)); //tworzenie pozycji o programie dla menu Pomoc
    menuPomoc->append(*menuitem_Oprogramie);



   vbox->show_all();

    return app->run(window);
}
