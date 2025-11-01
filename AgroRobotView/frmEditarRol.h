#pragma once

namespace AgroRobotView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace AgroRobotController;
	using namespace AgroRobotModel;

	/// <summary>
	/// Resumen de frmEditarRol
	/// </summary>
	public ref class frmEditarRol : public System::Windows::Forms::Form
	{
	public:
		frmEditarRol(RolController^ rolController, Rol^ rol)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			this->rolController = rolController;
			this->rol = rol;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmEditarRol()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	protected:
	private: System::Windows::Forms::CheckedListBox^ checkedListBox1;
	private: System::Windows::Forms::TextBox^ txtNombre;
	private: System::Windows::Forms::TextBox^ txtId;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnGrabar;
	private: System::Windows::Forms::Button^ btnCancelar;
	private: RolController^ rolController;
	private: Rol^ rol;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
			this->txtNombre = (gcnew System::Windows::Forms::TextBox());
			this->txtId = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnGrabar = (gcnew System::Windows::Forms::Button());
			this->btnCancelar = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->checkedListBox1);
			this->groupBox1->Controls->Add(this->txtNombre);
			this->groupBox1->Controls->Add(this->txtId);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(11, 11);
			this->groupBox1->Margin = System::Windows::Forms::Padding(2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(2);
			this->groupBox1->Size = System::Drawing::Size(361, 275);
			this->groupBox1->TabIndex = 5;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Datos del Rol";
			// 
			// checkedListBox1
			// 
			this->checkedListBox1->FormattingEnabled = true;
			this->checkedListBox1->Location = System::Drawing::Point(137, 132);
			this->checkedListBox1->Name = L"checkedListBox1";
			this->checkedListBox1->Size = System::Drawing::Size(173, 94);
			this->checkedListBox1->TabIndex = 8;
			// 
			// txtNombre
			// 
			this->txtNombre->Location = System::Drawing::Point(137, 85);
			this->txtNombre->Margin = System::Windows::Forms::Padding(2);
			this->txtNombre->Name = L"txtNombre";
			this->txtNombre->Size = System::Drawing::Size(173, 20);
			this->txtNombre->TabIndex = 7;
			// 
			// txtId
			// 
			this->txtId->Enabled = false;
			this->txtId->Location = System::Drawing::Point(137, 41);
			this->txtId->Margin = System::Windows::Forms::Padding(2);
			this->txtId->Name = L"txtId";
			this->txtId->Size = System::Drawing::Size(173, 20);
			this->txtId->TabIndex = 6;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(41, 132);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(52, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Permisos:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(41, 88);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(50, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Nombre: ";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(41, 44);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(22, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Id: ";
			// 
			// btnGrabar
			// 
			this->btnGrabar->Location = System::Drawing::Point(113, 303);
			this->btnGrabar->Margin = System::Windows::Forms::Padding(2);
			this->btnGrabar->Name = L"btnGrabar";
			this->btnGrabar->Size = System::Drawing::Size(56, 19);
			this->btnGrabar->TabIndex = 6;
			this->btnGrabar->Text = L"Grabar";
			this->btnGrabar->UseVisualStyleBackColor = true;
			this->btnGrabar->Click += gcnew System::EventHandler(this, &frmEditarRol::btnGrabar_Click);
			// 
			// btnCancelar
			// 
			this->btnCancelar->Location = System::Drawing::Point(204, 303);
			this->btnCancelar->Margin = System::Windows::Forms::Padding(2);
			this->btnCancelar->Name = L"btnCancelar";
			this->btnCancelar->Size = System::Drawing::Size(66, 19);
			this->btnCancelar->TabIndex = 7;
			this->btnCancelar->Text = L"Cancelar";
			this->btnCancelar->UseVisualStyleBackColor = true;
			this->btnCancelar->Click += gcnew System::EventHandler(this, &frmEditarRol::btnCancelar_Click);
			// 
			// frmEditarRol
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(383, 347);
			this->Controls->Add(this->btnCancelar);
			this->Controls->Add(this->btnGrabar);
			this->Controls->Add(this->groupBox1);
			this->Name = L"frmEditarRol";
			this->Text = L"frmEditarRol";
			this->Load += gcnew System::EventHandler(this, &frmEditarRol::frmEditarRol_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmEditarRol_Load(System::Object^ sender, System::EventArgs^ e) {
		this->txtId->Text = this->rol->GetId().ToString();
		this->txtNombre->Text = this->rol->GetNombre();

		this->checkedListBox1->Items->Add("Acceso a Administración");
		this->checkedListBox1->Items->Add("Editar");
		this->checkedListBox1->Items->Add("Eliminar");
		this->checkedListBox1->Items->Add("Ver");
		List<bool>^ listaPermisos = this->rol->GetPermisos();
		/*se encarga de marcar las cajas si detecta que dicho permiso es true*/
		for (int i = 0; i < this->checkedListBox1->Items->Count; i++) {
			if (listaPermisos[i]) {
				this->checkedListBox1->SetItemChecked(i, true);
			}
		}

		/*El rol de Administrador no puede quitarse permisos*/
		if (rol->GetId() == 1) {
			this->txtId->Enabled = false;
			this->checkedListBox1->Enabled = false;
		}
	}
	
	private: System::Void btnGrabar_Click(System::Object^ sender, System::EventArgs^ e) {
		int id = Convert::ToInt32(this->txtId->Text);
		String^ nombre = this->txtNombre->Text;
		List<bool>^ listaPermisos = gcnew List<bool>();
		for (int i = 0; i < this->checkedListBox1->Items->Count; i++) {
			listaPermisos->Add(this->checkedListBox1->GetItemChecked(i));
		}

		this->rolController->modificarRol(id, nombre, listaPermisos);
		MessageBox::Show("El rol se editó correctamente.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
		this->Close(); // Cierra el formulario actual
	}
	
	private: System::Void btnCancelar_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
