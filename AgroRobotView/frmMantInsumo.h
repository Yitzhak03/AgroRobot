#pragma once
#include "frmNuevoInsumo.h"
#include "frmEditInsumo.h"
namespace AgroRobotView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic; //Para List<>
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de frmMantInsumo
	/// </summary>
	public ref class frmMantInsumo : public System::Windows::Forms::Form {
	public:
		frmMantInsumo(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			currentFilter = nullptr;
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmMantInsumo()
		{
			if (components) {
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button5;
	protected:

	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;





	private: System::Windows::Forms::GroupBox^ groupBox1;



	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;





	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container^ components;
	private: System::Windows::Forms::Button^ button6;

		// Nuevo campo para recordar filtro actual (si null o vacío => mostrar todos)
		String^ currentFilter;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(11, 130);
			this->button5->Margin = System::Windows::Forms::Padding(2);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(226, 36);
			this->button5->TabIndex = 22;
			this->button5->Text = L"Mostrar todos";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &frmMantInsumo::button5_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(121, 183);
			this->button3->Margin = System::Windows::Forms::Padding(2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(116, 25);
			this->button3->TabIndex = 20;
			this->button3->Text = L"Editar";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &frmMantInsumo::button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(11, 183);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(102, 25);
			this->button2->TabIndex = 19;
			this->button2->Text = L"Nuevo";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmMantInsumo::button2_Click);
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
					this->Column2, this->Column3, this->Column5
			});
			this->dataGridView1->Location = System::Drawing::Point(251, 11);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(430, 311);
			this->dataGridView1->TabIndex = 18;
			this->dataGridView1->UserDeletingRow += gcnew System::Windows::Forms::DataGridViewRowCancelEventHandler(this, &frmMantInsumo::dataGridView1_UserDeletingRow);
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
			this->Column2->Width = 150;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Tipo";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			this->Column3->Width = 125;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Unidad";
			this->Column5->Name = L"Column5";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->comboBox1);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(11, 11);
			this->groupBox1->Margin = System::Windows::Forms::Padding(2);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(2);
			this->groupBox1->Size = System::Drawing::Size(226, 97);
			this->groupBox1->TabIndex = 17;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Criterios de Búsqueda";
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(55, 26);
			this->comboBox1->MaxDropDownItems = 15;
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(154, 21);
			this->comboBox1->TabIndex = 22;
			this->comboBox1->DropDown += gcnew System::EventHandler(this, &frmMantInsumo::comboBox1_DropDown);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(9, 62);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(70, 23);
			this->button1->TabIndex = 21;
			this->button1->Text = L"Buscar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmMantInsumo::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 31);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(34, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Tipo :";
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(11, 225);
			this->button4->Margin = System::Windows::Forms::Padding(2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(226, 25);
			this->button4->TabIndex = 21;
			this->button4->Text = L"Eliminar";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &frmMantInsumo::button4_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(11, 269);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(102, 23);
			this->button6->TabIndex = 23;
			this->button6->Text = L"Ver stock";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// frmMantInsumo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(691, 335);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->button2);
			this->Name = L"frmMantInsumo";
			this->Text = L"Registro de insumos";
			this->Load += gcnew System::EventHandler(this, &frmMantInsumo::frmMantInsumo_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
		//===============================================================================
		//==============================Nuevo============================================
		//===============================================================================
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		frmNuevoInsumo^ frm = gcnew frmNuevoInsumo();
		frm->ShowDialog();
		// Después de crear, refrescar respetando el filtro actual (si hay)
		RefreshGrid();
	}
		   //===============================================================================
		   //==============================Eliminar=========================================
		   //===============================================================================
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (dataGridView1->SelectedRows->Count > 0) {
			System::Windows::Forms::DialogResult result;
			result = MessageBox::Show(
				"¿Está seguro de eliminar el insumo seleccionado?",
				"Confirmar eliminación",
				MessageBoxButtons::YesNo,
				MessageBoxIcon::Question
			);
			if (result == System::Windows::Forms::DialogResult::Yes) {
				int id = Convert::ToInt32(dataGridView1->SelectedRows[0]->Cells[0]->Value);
				InsumoController^ insumoCtrl = gcnew InsumoController();
				insumoCtrl->eliminarInsumo(id);
				// En lugar de manipular directamente las filas, volvemos a cargar la grilla
				RefreshGrid();
			}
		} else {
			MessageBox::Show(
				"Debe seleccionar una fila para eliminar.",
				"Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
		}
	}
		   //Método para mostrar todos los insumos en el DataGridView
	private: System::Void mostrarGrilla(List<Insumo^>^ lista)
	{
		//Limpiar el DataGridView
		dataGridView1->Rows->Clear();
		//Cargar los insumos en el DataGridView
		for each (Insumo ^ insumo in lista) {
			dataGridView1->Rows->Add(
				Convert::ToString(insumo->Id),
				insumo->Nombre,
				insumo->Tipo,
				insumo->Unidad
			);
		}
	}

		   // Nuevo método: refrescar la grilla respetando el filtro guardado
	private: System::Void RefreshGrid()
	{
		InsumoController^ insumoCtrl = gcnew InsumoController();
		List<Insumo^>^ lista;

		if (!String::IsNullOrWhiteSpace(currentFilter)) {
			// Aplica filtro guardado
			lista = insumoCtrl->buscarPorTipo(currentFilter->Trim());
		} else {
			// Muestra todos
			lista = insumoCtrl->readTxt();
		}

		mostrarGrilla(lista);
	}

		   //===============================================================================
		   //==============================Buscar===========================================
		   //===============================================================================
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		//Validar campo vacio con trim
		if (String::IsNullOrWhiteSpace(comboBox1->Text->Trim())) {
			MessageBox::Show(
				"Debe ingresar un tipo para buscar.",
				"Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
			return;
		}
		//Guardar filtro actual
		currentFilter = comboBox1->Text->Trim();

		//Crear el controlador
		InsumoController^ insumoCtrl = gcnew InsumoController();
		List<Insumo^>^ lista = insumoCtrl->buscarPorTipo(currentFilter);
		//Cargar los insumos en el DataGridView
		mostrarGrilla(lista);
	}
	private: System::Void dataGridView1_UserDeletingRow(System::Object^ sender, System::Windows::Forms::DataGridViewRowCancelEventArgs^ e)
	{
		//Validar si realmente desea eliminar
		System::Windows::Forms::DialogResult result;
		result = MessageBox::Show(
			"¿Está seguro de eliminar el insumo?",
			"Confirmar eliminación",
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Question
		);
		if (result == System::Windows::Forms::DialogResult::No) {
			e->Cancel = true; //Cancelar la eliminación
		} else {
			int id = Convert::ToInt32(e->Row->Cells[0]->Value);
			InsumoController^ insumoCtrl = gcnew InsumoController();
			insumoCtrl->eliminarInsumo(id);
			RefreshGrid();
		}

	}
		   //===============================================================================
		   //==============================Editar===========================================
		   //===============================================================================
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (dataGridView1->SelectedRows->Count == 0) {
			MessageBox::Show(
				"Debe seleccionar una fila para editar.",
				"Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
			return;
		}

		frmEditInsumo^ frm = gcnew frmEditInsumo(
			Convert::ToInt32(
				dataGridView1->SelectedRows[0]->Cells[0]->Value
			)
		);
		frm->ShowDialog();
		//Actualizar la vista respetando el filtro actual
		RefreshGrid();
	}
	private: System::Void comboBox1_DropDown(System::Object^ sender, System::EventArgs^ e)
	{
		//Cargar los tipos de insumos en el comboBox
		comboBox1->Items->Clear();
		InsumoController^ insumoCtrl = gcnew InsumoController();
		List<String^>^ tipos = insumoCtrl->obtenerTiposInsumos();
		for each (String ^ tipo in tipos) {
			comboBox1->Items->Add(tipo);
		}
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// Quitar filtro guardado y mostrar todos
		currentFilter = nullptr;
		RefreshGrid();
	}
	private: System::Void frmMantInsumo_Load(System::Object^ sender, System::EventArgs^ e)
	{
		// Al cargar el formulario, mostrar todos los insumos
		RefreshGrid();
	}
};
}