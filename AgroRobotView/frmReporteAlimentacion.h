#pragma once

namespace AgroRobotView {

	using namespace System;
	using namespace System::IO;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Windows::Forms::DataVisualization::Charting;
	using namespace AgroRobotController;
	using namespace AgroRobotModel;

	public ref class frmReporteAlimentacion : public System::Windows::Forms::Form
	{
	public:
		frmReporteAlimentacion(void)
		{
			InitializeComponent();
			// APLICAR ESTILO PROFESIONAL AL INICIAR
			AplicarEstiloProfesional();
		}

	protected:
		~frmReporteAlimentacion()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnExportar;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnExportar = (gcnew System::Windows::Forms::Button());

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();

			// chart1
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(28, 80);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Pie;
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(675, 324);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";

			// label1
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Bold));
			this->label1->Location = System::Drawing::Point(23, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(337, 30);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Reporte de Consumo por Especie";

			// btnExportar
			this->btnExportar->Location = System::Drawing::Point(520, 25);
			this->btnExportar->Name = L"btnExportar";
			this->btnExportar->Size = System::Drawing::Size(180, 35);
			this->btnExportar->TabIndex = 2;
			this->btnExportar->Text = L"Exportar Datos";
			this->btnExportar->UseVisualStyleBackColor = true;
			this->btnExportar->Click += gcnew System::EventHandler(this, &frmReporteAlimentacion::btnExportar_Click);

			// frmReporteAlimentacion
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(735, 429);
			this->Controls->Add(this->btnExportar);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->chart1);
			this->Name = L"frmReporteAlimentacion";
			this->Text = L"Reporte de Alimentación";
			this->Load += gcnew System::EventHandler(this, &frmReporteAlimentacion::frmReporteAlimentacion_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

		// =========================================================
		// APLICAR ESTILO Y ESCALADO (AQUÍ ESTÁ LA LÓGICA)
		// =========================================================
		void AplicarEstiloProfesional() {
			// A) COLORES
			System::Drawing::Color colorFondo = System::Drawing::Color::FromArgb(238, 245, 233);
			System::Drawing::Color colorVerde = System::Drawing::Color::FromArgb(67, 160, 71);
			System::Drawing::Color colorTexto = System::Drawing::Color::FromArgb(30, 60, 30);

			// B) CONFIGURACIÓN VENTANA PADRE (Para que llene el MDI)
			this->BackColor = colorFondo;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->AutoSize = false;
			this->Dock = DockStyle::Fill;

			// C) CONTROLES FIJOS (Título y Botón)
			this->label1->ForeColor = colorTexto;
			this->label1->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Left);

			this->btnExportar->Left = this->ClientSize.Width - this->btnExportar->Width - 30; // Pegar derecha
			this->btnExportar->Anchor = static_cast<AnchorStyles>(AnchorStyles::Top | AnchorStyles::Right); // Mantener derecha

			this->btnExportar->BackColor = colorVerde;
			this->btnExportar->ForeColor = System::Drawing::Color::White;
			this->btnExportar->FlatStyle = FlatStyle::Flat;
			this->btnExportar->FlatAppearance->BorderSize = 0;
			this->btnExportar->Font = gcnew System::Drawing::Font("Segoe UI", 9, FontStyle::Bold);
			this->btnExportar->Cursor = Cursors::Hand;

			// D) ESCALADO DEL GRÁFICO (ESTA ES LA PARTE CLAVE)
			int margen = 30;
			this->chart1->Top = 80;
			this->chart1->Left = margen;

			// 1. Calculamos el tamaño inicial basado en la ventana actual
			this->chart1->Width = this->ClientSize.Width - (margen * 2);
			this->chart1->Height = this->ClientSize.Height - this->chart1->Top - margen;

			// 2. Aplicamos los 4 anclajes. Esto hace que el control contenedor se estire.
			this->chart1->Anchor = static_cast<AnchorStyles>(
				AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right);

			// Estilo limpio
			this->chart1->BackColor = System::Drawing::Color::White;
			this->chart1->BorderlineColor = System::Drawing::Color::Transparent;

			if (this->chart1->ChartAreas->Count > 0) this->chart1->ChartAreas[0]->BackColor = System::Drawing::Color::White;
			if (this->chart1->Legends->Count > 0) this->chart1->Legends[0]->ForeColor = colorTexto;
		}

	private: System::Void frmReporteAlimentacion_Load(System::Object^ sender, System::EventArgs^ e) {
		Dictionary<String^, int>^ contador = gcnew Dictionary<String^, int>();

		if (File::Exists("animales.txt")) {
			array<String^>^ lineas = File::ReadAllLines("animales.txt");
			for each (String ^ linea in lineas) {
				if (linea->Trim() == "") continue;
				array<String^>^ partes = linea->Split(';');
				if (partes->Length > 7) {
					String^ especie = partes[1];
					int veces = 0;
					try { veces = Convert::ToInt32(partes[7]); }
					catch (...) { veces = 0; }
					if (contador->ContainsKey(especie)) contador[especie] += veces;
					else contador->Add(especie, veces);
				}
			}
		}

		chart1->Series["Series1"]->Points->Clear();
		chart1->Series["Series1"]->ChartType = SeriesChartType::Pie;
		if (chart1->ChartAreas->Count > 0) chart1->ChartAreas[0]->Area3DStyle->Enable3D = false;

		// =========================================================
		// CORRECCIÓN CLAVE PARA PASTEL (PIE CHART)
		// Esto fuerza al pastel a usar todo el espacio del contenedor estirado
		// =========================================================
		if (chart1->ChartAreas->Count > 0) {
			// El área total del gráfico ocupa el 100% del control
			chart1->ChartAreas[0]->Position->Auto = false;
			chart1->ChartAreas[0]->Position->X = 0;
			chart1->ChartAreas[0]->Position->Y = 0;
			chart1->ChartAreas[0]->Position->Height = 100;
			chart1->ChartAreas[0]->Position->Width = 100;

			// El "InnerPlot" (donde se dibuja el pastel) también ocupa casi el 100%
			// Dejamos un pequeño margen (5%) para que las etiquetas externas no se corten
			chart1->ChartAreas[0]->InnerPlotPosition->Auto = false;
			chart1->ChartAreas[0]->InnerPlotPosition->X = 5;
			chart1->ChartAreas[0]->InnerPlotPosition->Y = 5;
			chart1->ChartAreas[0]->InnerPlotPosition->Height = 90;
			chart1->ChartAreas[0]->InnerPlotPosition->Width = 90;
		}
		// =========================================================

		chart1->Series["Series1"]->Font = gcnew System::Drawing::Font("Segoe UI", 10, FontStyle::Bold);
		chart1->Series["Series1"]->Label = "#VALX (#PERCENT)";
		chart1->Series["Series1"]->LegendText = "#VALX";
		chart1->Series["Series1"]->SetCustomProperty("PieLabelStyle", "Outside");
		chart1->Series["Series1"]->SmartLabelStyle->Enabled = true;
		chart1->Series["Series1"]->SmartLabelStyle->AllowOutsidePlotArea = System::Windows::Forms::DataVisualization::Charting::LabelOutsidePlotAreaStyle::Yes;

		for each (KeyValuePair<String^, int> kvp in contador) {
			int idx = chart1->Series["Series1"]->Points->AddXY(kvp.Key, kvp.Value);
			if (kvp.Key == "Pavo") chart1->Series["Series1"]->Points[idx]->Color = System::Drawing::Color::FromArgb(118, 222, 146);
			if (kvp.Key == "Pollo") chart1->Series["Series1"]->Points[idx]->Color = System::Drawing::Color::FromArgb(255, 200, 100);
			if (kvp.Key == "Cerdo") chart1->Series["Series1"]->Points[idx]->Color = System::Drawing::Color::FromArgb(100, 180, 255);
		}
	}

		   // Lógica de exportación (igual que antes)
	private: System::Void btnExportar_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			SaveFileDialog^ saveDialog = gcnew SaveFileDialog();
			saveDialog->Filter = "Reporte de Texto|*.txt";
			saveDialog->FileName = "Reporte_Alimentacion_" + DateTime::Now.ToString("yyyyMMdd_HHmmss") + ".txt";

			if (saveDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				StreamWriter^ writer = gcnew StreamWriter(saveDialog->FileName, false, System::Text::Encoding::UTF8);
				writer->WriteLine("AGROROBOT - REPORTE DE CONSUMO");
				writer->WriteLine("Fecha: " + DateTime::Now.ToString("g"));
				writer->WriteLine("------------------------------");

				Dictionary<String^, int>^ datos = gcnew Dictionary<String^, int>();
				if (File::Exists("animales.txt")) {
					array<String^>^ lineas = File::ReadAllLines("animales.txt");
					for each (String ^ linea in lineas) {
						if (linea->Trim() == "") continue;
						array<String^>^ p = linea->Split(';');
						if (p->Length > 7) {
							String^ sp = p[1];
							int v = 0; try { v = Convert::ToInt32(p[7]); }
							catch (...) { v = 0; }
							if (datos->ContainsKey(sp)) datos[sp] += v; else datos->Add(sp, v);
						}
					}
				}
				for each (KeyValuePair<String^, int> item in datos) {
					writer->WriteLine(item.Key + ": " + item.Value);
				}
				writer->Close();
				MessageBox::Show("Reporte exportado con éxito.");
			}
		}
		catch (Exception^ ex) { MessageBox::Show("Error: " + ex->Message); }
	}
	};
}