#ifndef MYWINDOW_H
#define MYWINDOW_H
#include <gtkmm.h>

class mywindow : public Gtk::Window
{
    public:
        mywindow();
        virtual ~mywindow();
    protected:
    void on_quit_click();
    void on_oprogramie_click();
    void dialog(Glib::ustring msg, Glib::ustring title);
    private:
};

#endif // MYWINDOW_H
