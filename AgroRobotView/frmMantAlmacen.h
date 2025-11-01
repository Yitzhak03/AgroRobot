#pragma once
#include "frmNuevoAlmacen.h"
#include "frmPaintStockPorAlmacen.h"
namespace AgroRobotView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic; // Para usar List<>
	// Referencias a controladores y modelos
	using namespace AgroRobotController;
	using namespace AgroRobotModel;

	/// <summary>
	/// Resumen de frmMantAlmacen
	/// </summary>
	public ref class frmMantAlmacen : public System::Windows::Forms::Form {
	public:
		frmMantAlmacen(void)
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
		~frmMantAlmacen()
		{
			if (components) {
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button4;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;




	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;






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
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(11, 49);
			this->button4->Margin = System::Windows::Forms::Padding(2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(100, 32);
			this->button4->TabIndex = 27;
			this->button4->Text = L"Mostrar";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &frmMantAlmacen::button4_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(11, 11);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(100, 34);
			this->button2->TabIndex = 25;
			this->button2->Text = L"Nuevo";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmMantAlmacen::button2_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToResizeColumns = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4)
			{
				this->Column1,
					this->Column2, this->Column3, this->Column4
			});
			this->dataGridView1->Location = System::Drawing::Point(141, 11);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(383, 259);
			this->dataGridView1->TabIndex = 24;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(11, 121);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 32);
			this->button1->TabIndex = 27;
			this->button1->Text = L"Agregar Insumos";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmMantAlmacen::button1_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(11, 85);
			this->button3->Margin = System::Windows::Forms::Padding(2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(100, 32);
			this->button3->TabIndex = 27;
			this->button3->Text = L"Ver Insumos";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &frmMantAlmacen::button3_Click);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Id";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			this->Column1->Width = 50;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Nombre";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			this->Column2->Width = 125;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Ubicación";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			this->Column3->Width = 125;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Insumos";
			this->Column4->MinimumWidth = 6;
			this->Column4->Name = L"Column4";
			this->Column4->Width = 80;
			// 
			// frmMantAlmacen
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(535, 281);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"frmMantAlmacen";
			this->Text = L"Registro General de Almacenes";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e)
	{
		AlmacenController^ almacenCtrl = gcnew AlmacenController();
		List<Almacen^>^ lista = almacenCtrl->readTxt();
		mostrarGrilla(lista);
	}
		   //Método para mostrar todos los insumos en el DataGridView
	private: System::Void mostrarGrilla(List<Almacen^>^ lista)
	{
		//Limpiar el DataGridView
		dataGridView1->Rows->Clear();
		//Crear el controlador de StockInsumo para contar insumos por almacén
		StockInsumoController^ SICtrl = gcnew StockInsumoController();
		//Cargar los insumos en el DataGridView
		for each (Almacen ^ a in lista) {
			dataGridView1->Rows->Add(
				Convert::ToString(a->Id),
				a->Nombre,
				a->Ubicacion,
				Convert::ToString(SICtrl->cantidadInsumosEnAlmacen(a->Id))
			);
		}
	}
		   //========================================================================
		   //=============================Nuevo======================================
		   //========================================================================
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		frmNuevoAlmacen^ frmNA = gcnew frmNuevoAlmacen();
		frmNA->ShowDialog();
	}
		   //========================================================================
		   //========================Agregar Insumos=================================
		   //========================================================================
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
	}
		   //========================================================================
		   //===========================Ver Insumos==================================
		   //========================================================================
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (dataGridView1->SelectedRows->Count == 0) {
			MessageBox::Show(
				"Debe seleccionar una fila para ver el stock.",
				"Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
			return;
		}
		int idAlmacen = Convert::ToInt32(dataGridView1->SelectedRows[0]->Cells[0]->Value);
		AlmacenController^ almCtrl = gcnew AlmacenController();
		Almacen^ almacen = almCtrl->buscarPorId(idAlmacen);
		StockInsumoController^ stockCtrl = gcnew StockInsumoController();
		List<StockInsumo^>^ stocks = stockCtrl->buscarPorIdAlmacen(idAlmacen);
		frmPaintStockPorAlmacen^ frm = gcnew frmPaintStockPorAlmacen(almacen, stocks);
		frm->ShowDialog();
	}
};
}
