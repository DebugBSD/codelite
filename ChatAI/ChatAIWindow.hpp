#pragma once

#include "ChatAIConfig.hpp"
#include "UI.hpp"
#include "cl_command_event.h"

class ChatAI;
class ChatAIWindow : public AssistanceAIChatWindowBase
{
public:
    ChatAIWindow(wxWindow* parent, ChatAI* plugin);
    virtual ~ChatAIWindow();
    void ShowSettings();

protected:
    void OnInputUI(wxUpdateUIEvent& event) override;
    void OnSend(wxCommandEvent& event) override;
    void OnSendUI(wxUpdateUIEvent& event) override;
    void OnUpdateTheme(wxCommandEvent& event);
    void OnKeyDown(wxKeyEvent& event);
    void OnSettings(wxCommandEvent& event);
    void OnClear(wxCommandEvent& event);
    void OnStartModel(wxCommandEvent& event);
    void OnStartModelUI(wxUpdateUIEvent& event);
    void OnStopModel(wxCommandEvent& event);
    void OnStopModelUI(wxUpdateUIEvent& event);
    void OnRestartModel(wxCommandEvent& event);
    void OnRestartModelUI(wxUpdateUIEvent& event);
    void UpdateTheme();
    void SendPromptEvent();
    void OnChatAIStarted(clCommandEvent& event);
    void OnChatAIOutput(clCommandEvent& event);
    void OnChatAIStderr(clCommandEvent& event);
    void OnChatAITerminated(clCommandEvent& event);
    void PopulateModels();
    void OnActiveModelChanged(wxCommandEvent& event);
    void SetFocusToActiveEditor();
    void AppendOutputText(const wxString& message);
    void PromptForModelReplace(const wxString& message);

private:
    ChatAI* m_plugin = nullptr;
    bool m_llamaCliRunning = false;
    wxChoice* m_activeModel = nullptr;
    bool m_autoRestart = false;
};

wxDECLARE_EVENT(wxEVT_CHATAI_SEND, clCommandEvent);
wxDECLARE_EVENT(wxEVT_CHATAI_STOP, clCommandEvent);
wxDECLARE_EVENT(wxEVT_CHATAI_START, clCommandEvent);
wxDECLARE_EVENT(wxEVT_CHATAI_INTERRUPT, clCommandEvent);
