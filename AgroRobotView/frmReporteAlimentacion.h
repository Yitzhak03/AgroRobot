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

	/// <summary>
	/// Resumen de frmReporteAlimentacion
	/// </summary>
	public ref class frmReporteAlimentacion : public System::Windows::Forms::Form
	{
	public:
		frmReporteAlimentacion(void)
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
		~frmReporteAlimentacion()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::Label^ label1;
	protected:

	protected:

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
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
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Bold));
			this->label1->Location = System::Drawing::Point(23, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(337, 30);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Reporte de Consumo por Especie";
			// 
			// frmReporteAlimentacion
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(735, 429);
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
	private: System::Void frmReporteAlimentacion_Load(System::Object^ sender, System::EventArgs^ e) {
		// Diccionario para acumular alimentaciones por especie
		Dictionary<String^, int>^ contador = gcnew Dictionary<String^, int>();

		/*FUNCIÓN PARA HACER DICCIONARIOS DE ESPECIES Y LA CANTIDAD DE ALIMENTO QUE CONSUME*/
		array<String^>^ lineas = File::ReadAllLines("animales.txt");

		for each (String ^ linea in lineas) {
			if (linea->Trim() == "") continue; // Evitar líneas vacías

			array<String^>^ partes = linea->Split(';');

			String^ especie = partes[1];
			int veces = Convert::ToInt32(partes[7]);

			// Acumular
			if (contador->ContainsKey(especie))
				contador[especie] += veces;
			else
				contador->Add(especie, veces);
		}

		// --- CONFIGURACIÓN DEL GRÁFICO ---

		chart1->Series["Series1"]->Points->Clear();
		chart1->Series["Series1"]->ChartType = SeriesChartType::Pie;
		chart1->ChartAreas[0]->Area3DStyle->Enable3D = false; // Sin 3D

		// 1. AUMENTAR TAMAÑO DE LETRA (Cambia 10 por 11 o 12 si quieres más grande)
		chart1->Series["Series1"]->Font = gcnew System::Drawing::Font("Arial", 10, FontStyle::Bold);

		// Etiqueta: Solo el nombre del animal
		chart1->Series["Series1"]->Label = "#VALX";

		// 2. SEPARACIÓN Y ESTILO (CALLOUT)
		chart1->Series["Series1"]->SetCustomProperty("PieLabelStyle", "Outside");
		chart1->Series["Series1"]->SetCustomProperty("PieLineColor", "Black");

		// TRUCO PARA SEPARAR: Permitir que las etiquetas usen el espacio blanco del borde
		// Esto hace que las líneas se estiren más hacia afuera para no amontonarse
		chart1->Series["Series1"]->SmartLabelStyle->Enabled = true;
		chart1->Series["Series1"]->SmartLabelStyle->AllowOutsidePlotArea = System::Windows::Forms::DataVisualization::Charting::LabelOutsidePlotAreaStyle::Yes;

		// Leyenda: Solo porcentaje
		chart1->Series["Series1"]->LegendText = "#PERCENT";
		chart1->Series["Series1"]->Legend = "Legend1";

		// Añadir datos al gráfico
		for each (KeyValuePair<String^, int> kvp in contador) {
			int idx = chart1->Series["Series1"]->Points->AddXY(kvp.Key, kvp.Value);

			if (kvp.Key == "Pavo") {
				chart1->Series["Series1"]->Points[idx]->Color = Color::LightGreen;
			}
		}
	}
	};
}
