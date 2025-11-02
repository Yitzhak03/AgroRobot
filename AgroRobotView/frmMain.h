#pragma once
#include "frmMenu.h"
namespace AgroRobotView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic; // Para usar List<>
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	//Referencias a los otros proyectos
	using namespace AgroRobotModel;
	using namespace AgroRobotController;

	/// <summary>
	/// Resumen de frmMain
	/// </summary>
	public ref class frmMain : public System::Windows::Forms::Form {
	public:
		frmMain(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmMain()
		{
			if (components) {
				delete components;
			}
		}

	protected:
	private: System::Windows::Forms::Panel^ panelCard;
	private: System::Windows::Forms::Label^ lblTitle;
	private: System::Windows::Forms::Label^ lblSubtitle;
	private: System::Windows::Forms::Label^ lblUser;
	private: System::Windows::Forms::TextBox^ txtUser;

	private: System::Windows::Forms::Label^ lblPassword;
	private: System::Windows::Forms::TextBox^ txtPassword;

	private: System::Windows::Forms::CheckBox^ chkVerContrasenha;
	private: System::Windows::Forms::Button^ btnLogin;
	private: System::Windows::Forms::Button^ btnHelp;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(frmMain::typeid));
			this->panelCard = (gcnew System::Windows::Forms::Panel());
			this->lblTitle = (gcnew System::Windows::Forms::Label());
			this->lblSubtitle = (gcnew System::Windows::Forms::Label());
			this->lblUser = (gcnew System::Windows::Forms::Label());
			this->txtUser = (gcnew System::Windows::Forms::TextBox());
			this->lblPassword = (gcnew System::Windows::Forms::Label());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->chkVerContrasenha = (gcnew System::Windows::Forms::CheckBox());
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->btnHelp = (gcnew System::Windows::Forms::Button());
			this->panelCard->SuspendLayout();
			this->SuspendLayout();
			// 
			// panelCard
			// 
			this->panelCard->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(12)), static_cast<System::Int32>(static_cast<System::Byte>(59)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->panelCard->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelCard->Controls->Add(this->lblTitle);
			this->panelCard->Controls->Add(this->lblSubtitle);
			this->panelCard->Controls->Add(this->lblUser);
			this->panelCard->Controls->Add(this->txtUser);
			this->panelCard->Controls->Add(this->lblPassword);
			this->panelCard->Controls->Add(this->txtPassword);
			this->panelCard->Controls->Add(this->chkVerContrasenha);
			this->panelCard->Controls->Add(this->btnLogin);
			this->panelCard->Controls->Add(this->btnHelp);
			this->panelCard->Location = System::Drawing::Point(190, 64);
			this->panelCard->Name = L"panelCard";
			this->panelCard->Size = System::Drawing::Size(366, 308);
			this->panelCard->TabIndex = 14;
			// 
			// lblTitle
			// 
			this->lblTitle->AutoSize = true;
			this->lblTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 16, System::Drawing::FontStyle::Bold));
			this->lblTitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(230)));
			this->lblTitle->Location = System::Drawing::Point(20, 16);
			this->lblTitle->Name = L"lblTitle";
			this->lblTitle->Size = System::Drawing::Size(126, 30);
			this->lblTitle->TabIndex = 0;
			this->lblTitle->Text = L"AgroRobot";
			// 
			// lblSubtitle
			// 
			this->lblSubtitle->AutoSize = true;
			this->lblSubtitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->lblSubtitle->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(191)), static_cast<System::Int32>(static_cast<System::Byte>(228)),
				static_cast<System::Int32>(static_cast<System::Byte>(198)));
			this->lblSubtitle->Location = System::Drawing::Point(22, 50);
			this->lblSubtitle->Name = L"lblSubtitle";
			this->lblSubtitle->Size = System::Drawing::Size(181, 15);
			this->lblSubtitle->TabIndex = 1;
			this->lblSubtitle->Text = L"Sistema de granja y alimentación";
			// 
			// lblUser
			// 
			this->lblUser->AutoSize = true;
			this->lblUser->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblUser->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(217)), static_cast<System::Int32>(static_cast<System::Byte>(242)),
				static_cast<System::Int32>(static_cast<System::Byte>(217)));
			this->lblUser->Location = System::Drawing::Point(22, 88);
			this->lblUser->Name = L"lblUser";
			this->lblUser->Size = System::Drawing::Size(49, 15);
			this->lblUser->TabIndex = 2;
			this->lblUser->Text = L"Usuario";
			// 
			// txtUser
			// 
			this->txtUser->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(38)),
				static_cast<System::Int32>(static_cast<System::Byte>(35)));
			this->txtUser->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtUser->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->txtUser->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(245)),
				static_cast<System::Int32>(static_cast<System::Byte>(234)));
			this->txtUser->Location = System::Drawing::Point(22, 108);
			this->txtUser->Name = L"txtUser";
			this->txtUser->Size = System::Drawing::Size(312, 25);
			this->txtUser->TabIndex = 0;
			this->txtUser->Text = L"Becquer";
			// 
			// lblPassword
			// 
			this->lblPassword->AutoSize = true;
			this->lblPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
			this->lblPassword->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(217)), static_cast<System::Int32>(static_cast<System::Byte>(242)),
				static_cast<System::Int32>(static_cast<System::Byte>(217)));
			this->lblPassword->Location = System::Drawing::Point(22, 148);
			this->lblPassword->Name = L"lblPassword";
			this->lblPassword->Size = System::Drawing::Size(69, 15);
			this->lblPassword->TabIndex = 3;
			this->lblPassword->Text = L"Contraseña";
			// 
			// txtPassword
			// 
			this->txtPassword->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(5)), static_cast<System::Int32>(static_cast<System::Byte>(38)),
				static_cast<System::Int32>(static_cast<System::Byte>(35)));
			this->txtPassword->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->txtPassword->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(232)), static_cast<System::Int32>(static_cast<System::Byte>(245)),
				static_cast<System::Int32>(static_cast<System::Byte>(234)));
			this->txtPassword->Location = System::Drawing::Point(22, 168);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->Size = System::Drawing::Size(312, 25);
			this->txtPassword->TabIndex = 1;
			this->txtPassword->Text = L"123456";
			this->txtPassword->UseSystemPasswordChar = true;
			// 
			// chkVerContrasenha
			// 
			this->chkVerContrasenha->AutoSize = true;
			this->chkVerContrasenha->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->chkVerContrasenha->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(159)),
				static_cast<System::Int32>(static_cast<System::Byte>(217)), static_cast<System::Int32>(static_cast<System::Byte>(176)));
			this->chkVerContrasenha->Location = System::Drawing::Point(22, 205);
			this->chkVerContrasenha->Name = L"chkVerContrasenha";
			this->chkVerContrasenha->Size = System::Drawing::Size(103, 19);
			this->chkVerContrasenha->TabIndex = 3;
			this->chkVerContrasenha->Text = L"Ver contraseña";
			this->chkVerContrasenha->UseVisualStyleBackColor = true;
			this->chkVerContrasenha->CheckedChanged += gcnew System::EventHandler(this, &frmMain::chkVerContrasenha_CheckedChanged);
			// 
			// btnLogin
			// 
			this->btnLogin->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(122)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
				static_cast<System::Int32>(static_cast<System::Byte>(140)));
			this->btnLogin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnLogin->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
			this->btnLogin->Location = System::Drawing::Point(22, 243);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(147, 36);
			this->btnLogin->TabIndex = 5;
			this->btnLogin->Text = L"Ingresar";
			this->btnLogin->UseVisualStyleBackColor = false;
			this->btnLogin->Click += gcnew System::EventHandler(this, &frmMain::btnLogin_Click);
			// 
			// btnHelp
			// 
			this->btnHelp->BackColor = System::Drawing::Color::Transparent;
			this->btnHelp->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnHelp->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
			this->btnHelp->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(159)), static_cast<System::Int32>(static_cast<System::Byte>(217)),
				static_cast<System::Int32>(static_cast<System::Byte>(176)));
			this->btnHelp->Location = System::Drawing::Point(190, 243);
			this->btnHelp->Name = L"btnHelp";
			this->btnHelp->Size = System::Drawing::Size(144, 36);
			this->btnHelp->TabIndex = 6;
			this->btnHelp->Text = L"Necesito ayuda";
			this->btnHelp->UseVisualStyleBackColor = true;
			// 
			// frmMain
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(753, 446);
			this->Controls->Add(this->panelCard);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"frmMain";
			this->Text = L"frmMain";
			this->panelCard->ResumeLayout(false);
			this->panelCard->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		//==============================================================================
		//==============================INGRESAR========================================
		//==============================================================================
	private: System::Void btnLogin_Click(System::Object^ sender, System::EventArgs^ e)
	{
		String^ usuario = txtUser->Text;
		String^ contrasenha = txtPassword->Text;

		// Validar campos vacíos
		if (String::IsNullOrEmpty(usuario) || String::IsNullOrEmpty(contrasenha)) {
			MessageBox::Show("Ingrese usuario y contraseña.", "Login", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		UsuarioController^ ctrl = gcnew UsuarioController();
		List<Usuario^>^ lista = ctrl->obtenerTodosUsuarios();

		for each (Usuario ^ u in lista) {
			// comparar nombre de usuario sin distinguir mayúsculas/minúsculas,
			// pero la contraseña sí (por convención)
			if (String::Compare(u->GetNombre(), usuario, false) == 0 && u->GetContrasenha()->Equals(contrasenha)) {
				// Autenticado
				MessageBox::Show("Acceso correcto. Bienvenido " + u->GetNombre(), "Login", MessageBoxButtons::OK, MessageBoxIcon::Information);
				// Aquí puedes guardar el usuario actual en una variable global/static o abrir el formulario principal
				this->Hide(); // Ocultar el formulario de login
				frmMenu^ menu = gcnew frmMenu(u); // Pasar el usuario autenticado
				menu->ShowDialog(); // Mostrar el formulario del menú principal
				this->Close(); // Cerrar el formulario de login al volver del menú
				return;
			}
		}
		// No encontrado / credenciales inválidas
		MessageBox::Show("Usuario o contraseña incorrectos.", "Login", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
		   //==============================================================================
		   //==============================Ver contraseña==================================
		   //==============================================================================
	private: System::Void chkVerContrasenha_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
	{
		if (chkVerContrasenha->Checked) {
			txtPassword->UseSystemPasswordChar = false; // Mostrar contraseña
		} else {
			txtPassword->UseSystemPasswordChar = true; // Ocultar contraseña
		}
	}
	};
}
