#pragma once

#include <gtkmm.h>
#include <gtkmm/printunixdialog.h>
#include <gtkmm/filefilter.h>
#include <gtkmm/application.h>

namespace Tabby {

  class MacDialogWindow : public Gtk::Window
  {
  public:
    MacDialogWindow(void);
    virtual ~MacDialogWindow(void) override;
    std::string GetFileName(void) const { return m_ChosenFile; }
    void SubmitTabbyFilter(const char* filter);

  protected:
    // Signal handlers
    void OnFileButtonClicked(void);

  private:
    std::string m_ChosenFile;
    std::string m_TBFilterName;
    std::string m_TBFilterPattern;
  };

}
