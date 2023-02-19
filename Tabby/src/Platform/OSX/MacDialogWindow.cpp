#include "tbpch.h"
#include "Platform/OSX/MacDialogWindow.h"

namespace Tabby {

  MacDialogWindow::MacDialogWindow(void)
  {
    set_title("Tabby Scene File Selector");
    signal_show().connect(sigc::mem_fun(*this, &MacDialogWindow::OnFileButtonClicked));
  }

  MacDialogWindow::~MacDialogWindow(void)
  {
  }

  void MacDialogWindow::SubmitTabbyFilter(const char* filter)
  {
    int i = 0;
    while (filter[i] != '\0') {
      m_TBFilterName += filter[i];
      i++;
    } // while (filter[i] != '\0') {

    TB_CORE_TRACE("m_TBFilterName = '{0}'", m_TBFilterName);

    i++; // Skip \0 character
    while (filter[i] != '\0') {
      m_TBFilterPattern += filter[i];
      i++;
    } // while (filter[i] != '\0') {

    TB_CORE_TRACE("m_TBFilterPattern = '{0}'", m_TBFilterPattern);

    return;
  }

  void MacDialogWindow::OnFileButtonClicked(void)
  {
    Gtk::FileChooserDialog dialog("Please choose a scene", Gtk::FILE_CHOOSER_ACTION_OPEN);
    dialog.set_transient_for(*this);

    // Add response buttons to the dialog
    dialog.add_button(Gtk::Stock::CANCEL, Gtk::RESPONSE_CANCEL);
    dialog.add_button(Gtk::Stock::OPEN, Gtk::RESPONSE_OK);

    // Add filters, so that only certain file types can be selected:

    Glib::RefPtr<Gtk::FileFilter> filterTabby = Gtk::FileFilter::create();
    filterTabby->set_name(m_TBFilterName);
    filterTabby->add_pattern(m_TBFilterPattern);
    dialog.add_filter(filterTabby);

    Glib::RefPtr<Gtk::FileFilter> filter_text = Gtk::FileFilter::create();
    filter_text->set_name("Text files");
    filter_text->add_mime_type("text/plain");
    dialog.add_filter(filter_text);

    Glib::RefPtr<Gtk::FileFilter> filter_cpp = Gtk::FileFilter::create();
    filter_cpp->set_name("C/C++ files");
    filter_cpp->add_mime_type("text/x-c");
    filter_cpp->add_mime_type("text/x-c++");
    filter_cpp->add_mime_type("text/x-c-header");
    filter_cpp->add_mime_type("text/x-c++-header");
    dialog.add_filter(filter_cpp);

    Glib::RefPtr<Gtk::FileFilter> filter_any = Gtk::FileFilter::create();
    filter_any->set_name("Any files");
    filter_any->add_pattern("*");
    dialog.add_filter(filter_any);

    // Show the dialog and wait for a user response:
    int result = dialog.run();

    // Handle the response:
    switch (result) {
    case Gtk::RESPONSE_OK:
    {
      // Notice this is a std::string, not a Glib::ustring.
      m_ChosenFile = dialog.get_filename();
      break;
    }
    case Gtk::RESPONSE_CANCEL:
    {
      break;
    }
    default:
    {
      break;
    }
    } // switch (result) {

    close();

    return;
  }

}
