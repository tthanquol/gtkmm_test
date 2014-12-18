#include "mywindow.h"

mywindow::mywindow()
{
    //ctor
    set_default_size(400, 200);
    set_title("Gtkmm Example");
    Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL,0)); //stworzenie nowego kontenera typu box z orientacją pionową
    add(*vbox); //dodanie vbox do okna głównego

    Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar()); //utworzenie paska menu
    vbox ->pack_start(*menubar,Gtk::PACK_SHRINK,0); //dodanie paska do vboxa



    Gtk::MenuItem *menuitem_plik = Gtk::manage(new Gtk::MenuItem("_Plik",true)); //tworzenie menu Plik
    menubar->append(*menuitem_plik);

    Gtk::Menu *menuPlik = Gtk::manage(new Gtk::Menu()); //tworzenie kontenera na pozycje menu
    menuitem_plik->set_submenu(*menuPlik);//dodanie kontenera do menu Plik

    Gtk::MenuItem *menuitem_open = Gtk::manage(new Gtk::MenuItem("_Nowy",true)); //tworzenie pozycji Nowy dla menu Plik
    menuPlik->append(*menuitem_open);

    Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Wyjdź",true)); //tworzenie pozycji Wyjdź dla menu Plik
    menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &mywindow::on_quit_click)); //gdy pozycja kliknięta
    menuPlik->append(*menuitem_quit);

    Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("Po_moc",true)); //tworzenie menu Pomoc
    menubar->append(*menuitem_help);

    Gtk::Menu *menuPomoc = Gtk::manage(new Gtk::Menu()); //tworzenie kontenera dla menu pomoc
    menuitem_help->set_submenu(*menuPomoc);

    Gtk::MenuItem *menuitem_Oprogramie = Gtk::manage(new Gtk::MenuItem("O pr_ogramie",true)); //tworzenie pozycji o programie dla menu Pomoc

    menuitem_Oprogramie->signal_activate().connect(sigc::mem_fun(*this, &mywindow::on_oprogramie_click));
    menuPomoc->append(*menuitem_Oprogramie);

    Gtk::Grid *grid =Gtk::manage(new Gtk::Grid); //dodanie kontenera typu "siatka"
    grid->set_border_width(10);
    vbox->add(*grid); //dodanie grida do vboxa

    Gtk::Button *button1 =Gtk::manage(new Gtk::Button("Przycisk"));
    grid->attach(*button1,1,1,2,2);
    Gtk::Button *button2 =Gtk::manage(new Gtk::Button("Przycisk"));
    grid->attach(*button2,3,2,1,1);

    vbox->show_all();

}

mywindow::~mywindow()
{
    //dtor
}
void mywindow::on_oprogramie_click()
{
    dialog("Przykładowe okno gtkmm","O programie");
}
void mywindow::dialog(Glib::ustring msg, Glib::ustring title)
{
    Gtk::MessageDialog dlg(msg, false, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, true);
    dlg.set_title(title);
    dlg.run();

}

void mywindow::on_quit_click()
{
    hide();
}
