#pragma once

namespace AgroRobotView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic; //Para List<>
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace AgroRobotController; // Referencia al proyecto AgroRobotController
	using namespace AgroRobotModel; // Referencia al proyecto AgroRobotModel

	/// <summary>
	/// Resumen de frmEditarReporte
	/// </summary>
	public ref class frmEditarReporte : public System::Windows::Forms::Form
	{
	public:
		frmEditarReporte(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

		frmEditarReporte(ReporteController^ reporteController, Reporte^ objReporte)
		{
			InitializeComponent();
			this->reporteController = reporteController;
			this->objReporte = objReporte;
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~frmEditarReporte()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	protected:






	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::ComboBox^ comboBox2;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::CheckBox^ checkBox5;
	private: System::Windows::Forms::CheckBox^ checkBox4;
	private: System::Windows::Forms::CheckBox^ checkBox3;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::CheckBox^ checkBox6;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: ReporteController^ reporteController;
	private: Reporte^ objReporte;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;

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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->checkBox6 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ControlDarkDark;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->Column1,
					this->Column2, this->Column3, this->Column4, this->Column5, this->Column6
			});
			this->dataGridView1->GridColor = System::Drawing::SystemColors::ControlDarkDark;
			this->dataGridView1->Location = System::Drawing::Point(31, 43);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(661, 150);
			this->dataGridView1->TabIndex = 0;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->dateTimePicker1);
			this->groupBox1->Controls->Add(this->comboBox2);
			this->groupBox1->Controls->Add(this->comboBox1);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Location = System::Drawing::Point(31, 219);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(281, 149);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Diagnóstico Actual";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(129, 119);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(134, 20);
			this->textBox1->TabIndex = 6;
			// 
			// label4
			// 
			this->label4->Location = System::Drawing::Point(24, 119);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(99, 27);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Veterinario Responsable:";
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dateTimePicker1->Location = System::Drawing::Point(129, 87);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(134, 20);
			this->dateTimePicker1->TabIndex = 4;
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Bajo", L"Medio", L"Alto", L"Urgente" });
			this->comboBox2->Location = System::Drawing::Point(129, 60);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(134, 21);
			this->comboBox2->TabIndex = 3;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Excelente", L"Bueno", L"Regular", L"Crítico" });
			this->comboBox1->Location = System::Drawing::Point(129, 33);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(134, 21);
			this->comboBox1->TabIndex = 2;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(24, 91);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(99, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Fecha Diagnóstico:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(24, 63);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(48, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Impacto:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(24, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(88, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Estado de Salud:";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->checkBox6);
			this->groupBox2->Controls->Add(this->checkBox5);
			this->groupBox2->Controls->Add(this->checkBox4);
			this->groupBox2->Controls->Add(this->checkBox3);
			this->groupBox2->Controls->Add(this->checkBox2);
			this->groupBox2->Controls->Add(this->checkBox1);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->textBox2);
			this->groupBox2->Location = System::Drawing::Point(340, 219);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(352, 227);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Observaciones";
			this->groupBox2->Enter += gcnew System::EventHandler(this, &frmEditarReporte::groupBox2_Enter);
			// 
			// checkBox6
			// 
			this->checkBox6->AutoSize = true;
			this->checkBox6->Location = System::Drawing::Point(259, 194);
			this->checkBox6->Name = L"checkBox6";
			this->checkBox6->Size = System::Drawing::Size(57, 17);
			this->checkBox6->TabIndex = 7;
			this->checkBox6->Text = L"Otro(s)";
			this->checkBox6->UseVisualStyleBackColor = true;
			// 
			// checkBox5
			// 
			this->checkBox5->AutoSize = true;
			this->checkBox5->Location = System::Drawing::Point(151, 164);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(84, 17);
			this->checkBox5->TabIndex = 6;
			this->checkBox5->Text = L"Seguimiento";
			this->checkBox5->UseVisualStyleBackColor = true;
			// 
			// checkBox4
			// 
			this->checkBox4->Location = System::Drawing::Point(259, 152);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(80, 40);
			this->checkBox4->TabIndex = 5;
			this->checkBox4->Text = L"Aislamiento preventivo";
			this->checkBox4->UseVisualStyleBackColor = true;
			// 
			// checkBox3
			// 
			this->checkBox3->AutoSize = true;
			this->checkBox3->Location = System::Drawing::Point(18, 194);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(106, 17);
			this->checkBox3->TabIndex = 4;
			this->checkBox3->Text = L"Consulta urgente";
			this->checkBox3->UseVisualStyleBackColor = true;
			// 
			// checkBox2
			// 
			this->checkBox2->Location = System::Drawing::Point(151, 187);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(80, 31);
			this->checkBox2->TabIndex = 3;
			this->checkBox2->Text = L"Administrar suplementos";
			this->checkBox2->UseVisualStyleBackColor = true;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Location = System::Drawing::Point(18, 164);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(84, 17);
			this->checkBox1->TabIndex = 2;
			this->checkBox1->Text = L"Ajustar dieta";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(9, 140);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(81, 13);
			this->label5->TabIndex = 1;
			this->label5->Text = L"Plan de acción:";
			// 
			// textBox2
			// 
			this->textBox2->ForeColor = System::Drawing::Color::Gray;
			this->textBox2->Location = System::Drawing::Point(20, 25);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(313, 103);
			this->textBox2->TabIndex = 0;
			this->textBox2->Text = L"Inserte observaciones y ajustes manuales...";
			this->textBox2->Enter += gcnew System::EventHandler(this, &frmEditarReporte::textBox2_Enter);
			this->textBox2->Leave += gcnew System::EventHandler(this, &frmEditarReporte::textBox2_Leave);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(198, 406);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Cancelar";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmEditarReporte::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(79, 406);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 6;
			this->button1->Text = L"Guardar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &frmEditarReporte::button1_Click);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"ID Evaluación";
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Animal";
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Tipo Análisis";
			this->Column3->Name = L"Column3";
			this->Column3->ReadOnly = true;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Fecha Generación";
			this->Column4->Name = L"Column4";
			this->Column4->ReadOnly = true;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Estado Salud";
			this->Column5->Name = L"Column5";
			this->Column5->ReadOnly = true;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Impacto";
			this->Column6->Name = L"Column6";
			this->Column6->ReadOnly = true;
			// 
			// frmEditarReporte
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(714, 458);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->dataGridView1);
			this->Name = L"frmEditarReporte";
			this->Text = L"Edición de Evaluación Continua - Administrador";
			this->Load += gcnew System::EventHandler(this, &frmEditarReporte::frmEditarReporte_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void textBox2_Enter(System::Object^ sender, System::EventArgs^ e) {
		if (textBox2->Text == "Inserte observaciones y ajustes manuales...")
		{
			textBox2->Text = "";
			textBox2->ForeColor = System::Drawing::Color::Black;
		}
	}
private: System::Void textBox2_Leave(System::Object^ sender, System::EventArgs^ e) {
	if (textBox2->Text == "")
	{
		textBox2->Text = "Inserte observaciones y ajustes manuales...";
		textBox2->ForeColor = System::Drawing::Color::Gray;
	}
}

private: System::Void checkBox1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	ActualizarContenidoConPlanAccion();
}

private: System::Void checkBox2_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	ActualizarContenidoConPlanAccion();
}

private: System::Void checkBox3_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	ActualizarContenidoConPlanAccion();
}

private: System::Void checkBox4_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	ActualizarContenidoConPlanAccion();
}

private: System::Void checkBox5_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	ActualizarContenidoConPlanAccion();
}

private: System::Void checkBox6_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	ActualizarContenidoConPlanAccion();
}

private: void ActualizarContenidoConPlanAccion() {
	// Si el usuario ya empezó a escribir, no sobreescribimos automáticamente
	if (textBox2->ForeColor == Color::Black &&
		!String::IsNullOrWhiteSpace(textBox2->Text) &&
		textBox2->Text != "Inserte observaciones y ajustes manuales...") {
		return;
	}

	// Construir contenido sugerido basado en checkboxes seleccionados
	String^ planAccion = ObtenerPlanAccionDeCheckboxes();
	if (!String::IsNullOrWhiteSpace(planAccion)) {
		textBox2->Text = "Plan de acción seleccionado: " + planAccion +
			"\n\nObservaciones adicionales:";
		textBox2->ForeColor = Color::Black;
	}
}


private: System::Void groupBox2_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void frmEditarReporte_Load(System::Object^ sender, System::EventArgs^ e) {
	if (this->objReporte != nullptr) {
		CargarDatosReporte();
	}
	else {
		MessageBox::Show("Error: No se ha proporcionado una evaluación válida para editar.", // CAMBIAR AQUÍ
			"Error",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error);
		this->Close();
	}
}

private: void CargarDatosReporte() {
	try {
		// 1. Cargar DataGridView (solo lectura)
		dataGridView1->Rows->Clear();
		int rowIndex = dataGridView1->Rows->Add();
		DataGridViewRow^ row = dataGridView1->Rows[rowIndex];

		// CAMBIAR "REP-" por "EVA-"
		row->Cells["Column1"]->Value = "EVA-" + objReporte->getIdReporte().ToString("D3");
		row->Cells["Column2"]->Value = objReporte->getAnimalAlias();
		row->Cells["Column3"]->Value = objReporte->getTipo();
		row->Cells["Column4"]->Value = objReporte->getFechaGeneracion().ToString("dd/MM/yyyy");
		row->Cells["Column5"]->Value = objReporte->getEstadoSaludImpacto();
		row->Cells["Column6"]->Value = ObtenerImpactoDesdeEstado(objReporte->getEstadoSaludImpacto());

		// 2. Cargar campos editables del diagnóstico
		comboBox1->SelectedItem = objReporte->getEstadoSaludImpacto();
		comboBox2->SelectedItem = ObtenerImpactoDesdeEstado(objReporte->getEstadoSaludImpacto());
		dateTimePicker1->Value = objReporte->getFechaGeneracion();

		// 3. Cargar contenido existente (recomendaciones/observaciones)
		textBox2->Text = objReporte->getContenido();
		if (!String::IsNullOrWhiteSpace(textBox2->Text)) {
			textBox2->ForeColor = Color::Black;
		}

		// 4. Veterinario responsable
		textBox1->Text = "";

		// 5. Cargar checkboxes del plan de acción basado en el contenido existente
		CargarCheckboxesDesdeContenido();

		// 6. Actualizar título del formulario - CAMBIAR AQUÍ
		this->Text = "Edición de Evaluación - EVA-" + objReporte->getIdReporte().ToString("D3");

	}
	catch (Exception^ ex) {
		MessageBox::Show("Error al cargar los datos de la evaluación: " + ex->Message, // CAMBIAR AQUÍ
			"Error",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error);
	}
}

private: String^ ObtenerImpactoDesdeEstado(String^ estado) {
	if (estado == "Crítico") return "Urgente";
	if (estado == "Regular") return "Alto";
	if (estado == "Bueno") return "Medio";
	if (estado == "Excelente") return "Bajo";
	return "Desconocido";
}

private: void CargarCheckboxesDesdeContenido() {
	// Analizar el contenido existente para pre-seleccionar checkboxes
	String^ contenido = objReporte->getContenido();

	if (String::IsNullOrWhiteSpace(contenido)) return;

	// Lógica simple para detectar acciones en el contenido
	if (contenido->ToLower()->Contains("dieta") || contenido->ToLower()->Contains("aliment")) {
		checkBox1->Checked = true;
	}
	if (contenido->ToLower()->Contains("suplemento") || contenido->ToLower()->Contains("vitamina")) {
		checkBox2->Checked = true;
	}
	if (contenido->ToLower()->Contains("consulta") || contenido->ToLower()->Contains("urgente")) {
		checkBox3->Checked = true;
	}
	if (contenido->ToLower()->Contains("aislamiento") || contenido->ToLower()->Contains("preventivo")) {
		checkBox4->Checked = true;
	}
	if (contenido->ToLower()->Contains("seguimiento") || contenido->ToLower()->Contains("control")) {
		checkBox5->Checked = true;
	}
}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	try {
		// 1. VALIDAR DATOS
		if (!ValidarDatos()) {
			return;
		}

		// 2. CONFIRMAR GUARDADO - CAMBIAR AQUÍ
		System::Windows::Forms::DialogResult resultado = MessageBox::Show(
			"¿Está seguro que desea guardar los cambios en la evaluación?",
			"Confirmar guardado",
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Question
		);

		if (resultado == System::Windows::Forms::DialogResult::No) {
			return;
		}

		// 3. ACTUALIZAR EL OBJETO REPORTE
		ActualizarObjetoReporte();

		// 4. GUARDAR EN LA BASE DE DATOS
		bool exito = reporteController->ModificarReporte(objReporte);

		if (exito) {
			MessageBox::Show("Los cambios se guardaron correctamente.",
				"Éxito",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information);
			this->Close();
		}
		else {
			MessageBox::Show("Error al guardar los cambios en la base de datos.",
				"Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error);
		}
	}
	catch (Exception^ ex) {
		MessageBox::Show("Error al guardar la evaluación: " + ex->Message, // CAMBIAR AQUÍ
			"Error",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error);
	}
	
}

private: bool ValidarDatos() {
	// Validar estado de salud seleccionado
	if (comboBox1->SelectedItem == nullptr) {
		MessageBox::Show("Por favor seleccione un estado de salud.",
			"Validación",
			MessageBoxButtons::OK,
			MessageBoxIcon::Warning);
		comboBox1->Focus();
		return false;
	}

	// Validar impacto seleccionado
	if (comboBox2->SelectedItem == nullptr) {
		MessageBox::Show("Por favor seleccione un nivel de impacto.",
			"Validación",
			MessageBoxButtons::OK,
			MessageBoxIcon::Warning);
		comboBox2->Focus();
		return false;
	}

	// Validar observaciones (opcional pero recomendado)
	if (String::IsNullOrWhiteSpace(textBox2->Text) ||
		textBox2->Text == "Inserte observaciones y ajustes manuales...") {
		System::Windows::Forms::DialogResult resultado = MessageBox::Show(
			"No ha ingresado observaciones. ¿Desea continuar sin observaciones?",
			"Observaciones vacías",
			MessageBoxButtons::YesNo,
			MessageBoxIcon::Question
		);
		return (resultado == System::Windows::Forms::DialogResult::Yes);
	}

	return true;
}

private: void ActualizarObjetoReporte() {
	// 1. Actualizar estado de salud e impacto
	String^ nuevoEstado = comboBox1->SelectedItem->ToString();
	objReporte->setEstadoSaludImpacto(nuevoEstado);

	// 2. Actualizar fecha de diagnóstico (si se cambió)
	// objReporte->setFechaGeneracion(dateTimePicker1->Value);
	// Nota: La fecha de generación original probablemente no debería cambiarse

	// 3. Construir el nuevo contenido combinando observaciones y plan de acción
	String^ nuevoContenido = ConstruirNuevoContenido();
	objReporte->setContenido(nuevoContenido);

	// 4. Actualizar estado de gestión (podría cambiar según las modificaciones)
	objReporte->setEstadoGestion("Revisado y Actualizado");
}

private: String^ ConstruirNuevoContenido() {
	String^ contenido = textBox2->Text;

	// Agregar información del veterinario si se proporcionó
	if (!String::IsNullOrWhiteSpace(textBox1->Text)) {
		contenido += "\n\nVeterinario responsable: " + textBox1->Text;
	}

	// Agregar plan de acción basado en checkboxes seleccionados
	String^ planAccion = ObtenerPlanAccionDeCheckboxes();
	if (!String::IsNullOrWhiteSpace(planAccion)) {
		contenido += "\n\nPlan de acción: " + planAccion;
	}

	// Agregar fecha de modificación
	contenido += "\n\nÚltima modificación: " + DateTime::Now.ToString("dd/MM/yyyy HH:mm") +
		" - Estado: " + comboBox1->SelectedItem->ToString();

	return contenido;
}

private: String^ ObtenerPlanAccionDeCheckboxes() {
	List<String^>^ acciones = gcnew List<String^>();

	if (checkBox1->Checked) acciones->Add("Ajustar dieta");
	if (checkBox2->Checked) acciones->Add("Administrar suplementos");
	if (checkBox3->Checked) acciones->Add("Consulta veterinaria urgente");
	if (checkBox4->Checked) acciones->Add("Aislamiento preventivo");
	if (checkBox5->Checked) acciones->Add("Seguimiento programado");
	if (checkBox6->Checked) acciones->Add("Otras acciones específicas");

	if (acciones->Count == 0) return "";

	return String::Join(", ", acciones->ToArray());
}

private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	//logica para cancelar la edición y cerrar el formulario

	try {
		// Verificar si hay cambios no guardados
		if (HayCambiosSinGuardar()) {
			System::Windows::Forms::DialogResult resultado = MessageBox::Show(
				"Tiene cambios sin guardar. ¿Está seguro que desea cancelar?\n\nLos cambios se perderán.",
				"Cambios sin guardar",
				MessageBoxButtons::YesNo,
				MessageBoxIcon::Warning,
				MessageBoxDefaultButton::Button2
			);

			if (resultado == System::Windows::Forms::DialogResult::No) {
				return;
			}
		}

		this->Close();

	}
	catch (Exception^ ex) {
		MessageBox::Show("Error al cerrar el formulario: " + ex->Message,
			"Error",
			MessageBoxButtons::OK,
			MessageBoxIcon::Error);
	}

}

private: bool HayCambiosSinGuardar() {
	// Verificar si se modificó el estado de salud
	if (comboBox1->SelectedItem != nullptr &&
		comboBox1->SelectedItem->ToString() != objReporte->getEstadoSaludImpacto()) {
		return true;
	}

	// Verificar si se modificaron las observaciones
	String^ contenidoActual = textBox2->Text;
	if (contenidoActual != "Inserte observaciones y ajustes manuales..." &&
		contenidoActual != objReporte->getContenido()) {
		return true;
	}

	// Verificar si se seleccionó algún checkbox
	if (checkBox1->Checked || checkBox2->Checked || checkBox3->Checked ||
		checkBox4->Checked || checkBox5->Checked || checkBox6->Checked) {
		return true;
	}

	return false;
}

};
}
