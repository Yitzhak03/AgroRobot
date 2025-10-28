#pragma once
#include "frmMantUsuarios.h"
#include "frmMantInsumo.h"
#include "frmMantReportes.h"
namespace AgroRobotView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace AgroRobotModel; // Referencia al proyecto AgroRobotModel
	/// <summary>
	/// Resumen de frmMenu
	/// </summary>
	public ref class frmMenu : public System::Windows::Forms::Form {
	public:
		frmMenu(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}
		// Nuevo constructor para recibir el usuario autenticado
		frmMenu(Usuario^ usuario)
		{
			this->usuario = usuario;
			InitializeComponent();

		}
	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmMenu()
		{
			if (components) {
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	protected:
	private: System::Windows::Forms::ToolStripMenuItem^ admnistracionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ diagnosticoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ planDeAlimentacionToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ almacenToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ reportesToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ volverToolStripMenuItem;
	private: Usuario^ usuario;
	private: System::Windows::Forms::ToolStripMenuItem^ registroInsumosGeneralToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ gestiónDeReportesToolStripMenuItem;

	private:
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
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->admnistracionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->diagnosticoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->planDeAlimentacionToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->almacenToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->registroInsumosGeneralToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->reportesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->volverToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->gestiónDeReportesToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->admnistracionToolStripMenuItem,
					this->diagnosticoToolStripMenuItem, this->planDeAlimentacionToolStripMenuItem, this->almacenToolStripMenuItem, this->reportesToolStripMenuItem,
					this->volverToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(854, 24);
			this->menuStrip1->TabIndex = 1;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// admnistracionToolStripMenuItem
			// 
			this->admnistracionToolStripMenuItem->Name = L"admnistracionToolStripMenuItem";
			this->admnistracionToolStripMenuItem->Size = System::Drawing::Size(100, 20);
			this->admnistracionToolStripMenuItem->Text = L"Administracion";
			this->admnistracionToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMenu::admnistracionToolStripMenuItem_Click);
			// 
			// diagnosticoToolStripMenuItem
			// 
			this->diagnosticoToolStripMenuItem->Name = L"diagnosticoToolStripMenuItem";
			this->diagnosticoToolStripMenuItem->Size = System::Drawing::Size(82, 20);
			this->diagnosticoToolStripMenuItem->Text = L"Diagnostico";
			this->diagnosticoToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMenu::diagnosticoToolStripMenuItem_Click);
			// 
			// planDeAlimentacionToolStripMenuItem
			// 
			this->planDeAlimentacionToolStripMenuItem->Name = L"planDeAlimentacionToolStripMenuItem";
			this->planDeAlimentacionToolStripMenuItem->Size = System::Drawing::Size(130, 20);
			this->planDeAlimentacionToolStripMenuItem->Text = L"Plan de alimentacion";
			// 
			// almacenToolStripMenuItem
			// 
			this->almacenToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->registroInsumosGeneralToolStripMenuItem });
			this->almacenToolStripMenuItem->Name = L"almacenToolStripMenuItem";
			this->almacenToolStripMenuItem->Size = System::Drawing::Size(66, 20);
			this->almacenToolStripMenuItem->Text = L"Almacen";
			// 
			// registroInsumosGeneralToolStripMenuItem
			// 
			this->registroInsumosGeneralToolStripMenuItem->Name = L"registroInsumosGeneralToolStripMenuItem";
			this->registroInsumosGeneralToolStripMenuItem->Size = System::Drawing::Size(208, 22);
			this->registroInsumosGeneralToolStripMenuItem->Text = L"Registro Insumos General";
			this->registroInsumosGeneralToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMenu::registroInsumosGeneralToolStripMenuItem_Click);
			// 
			// reportesToolStripMenuItem
			// 
			this->reportesToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->gestiónDeReportesToolStripMenuItem });
			this->reportesToolStripMenuItem->Name = L"reportesToolStripMenuItem";
			this->reportesToolStripMenuItem->Size = System::Drawing::Size(65, 20);
			this->reportesToolStripMenuItem->Text = L"Reportes";
			// 
			// volverToolStripMenuItem
			// 
			this->volverToolStripMenuItem->Name = L"volverToolStripMenuItem";
			this->volverToolStripMenuItem->Size = System::Drawing::Size(51, 20);
			this->volverToolStripMenuItem->Text = L"Volver";
			// 
			// gestiónDeReportesToolStripMenuItem
			// 
			this->gestiónDeReportesToolStripMenuItem->Name = L"gestiónDeReportesToolStripMenuItem";
			this->gestiónDeReportesToolStripMenuItem->Size = System::Drawing::Size(180, 22);
			this->gestiónDeReportesToolStripMenuItem->Text = L"Gestión de Reportes";
			this->gestiónDeReportesToolStripMenuItem->Click += gcnew System::EventHandler(this, &frmMenu::gestiónDeReportesToolStripMenuItem_Click);
			// 
			// frmMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(854, 527);
			this->Controls->Add(this->menuStrip1);
			this->IsMdiContainer = true;
			this->Name = L"frmMenu";
			this->Text = L"frmMenu";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//===============================================================================
		//==============================Administracion===================================
		//===============================================================================
	private: System::Void admnistracionToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		frmMantUsuarios^ frm = gcnew frmMantUsuarios();
		if (this->usuario->Nombre == "Becquer") {
			frm->MdiParent = this;
			frm->Show();
		} else {
			MessageBox::Show("Usted no tiene acceso al módulo de Administración.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

	}

	private: System::Void diagnosticoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
	}
		//===============================================================================
		//==============================Registro Insumos General=========================
		//===============================================================================
	private: System::Void registroInsumosGeneralToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
	{
		frmMantInsumo^ frm = gcnew frmMantInsumo();
		frm->MdiParent = this;
		frm->Show();
	}
	private: System::Void gestiónDeReportesToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		frmMantReportes^ reportesForm = gcnew frmMantReportes();
		reportesForm->MdiParent = this;
		reportesForm->Show();
	}
};
}
